import os
import argparse
import math
import h5py
import tensorflow as tf
import tf_util as U
import numpy as np
import sympy as sp

from scipy.special import comb
from numpy import linalg as LA
from scipy.optimize import linprog
from polyval import polyval


def nn_poly_approx_bernstein(
    f,
    state_vars,
    degree_bound,
    input_box,
    output_index
):
    """
    bernstein polynomial approximation of a given function f
    on a general box space
    f: a function
    state_var: the input variable of f
    d: degree bound vector of bernstein polynomial
    box: box space of state variables [alpha_1, beta_1] times cdots
    times [alpha_m, beta_m]
    """
    input_dim = len(state_vars)
    x = state_vars
    all_comb_lists = degree_comb_lists(degree_bound, input_dim)
    bernstein = 0
    poly_min = np.inf
    poly_max = -np.inf
    # construct bernstein polynomial for recover function + nerual network
    y = sp.symbols('y:'+str(input_dim))
    for cb in all_comb_lists:
        point = []
        for j in range(input_dim):
            k_j = cb[j]
            d_j = degree_bound[j]
            # linear transformation to normalize the box to I=[0,1]^m
            # lower bound of the j-th component
            alpha_j = np.float64(input_box[j][0])
            # upper bound of the j-th component
            beta_j = np.float64(input_box[j][1])
            point.append(
                (beta_j - alpha_j) *
                (cb[j] / degree_bound[j])
                + alpha_j
            )
        monomial = f(np.array(point, dtype=np.float64))[output_index]
        if monomial < poly_min:
            poly_min = monomial
        if monomial > poly_max:
            poly_max = monomial
        for j in range(input_dim):
            y_j = y[j]
            k_j = cb[j]
            d_j = degree_bound[j]
            monomial = (
                monomial * comb(d_j, k_j) *
                (y_j**k_j) * ((1 - y_j)**(d_j - k_j))
            )
        bernstein = bernstein + monomial
    poly_approx = bernstein[0]
    for j in range(input_dim):
        y_j = y[j]
        x_j = x[j]
        alpha_j = np.float64(input_box[j][0])
        beta_j = np.float64(input_box[j][1])
        poly_approx = poly_approx.subs(
            y_j, (x_j - alpha_j) / (beta_j - alpha_j)
        )
    return poly_approx, poly_min[0], poly_max[0]


def nn_poly_approx_bernstein_cuda(f, d, box, output_index):
    m = len(d)
    all_comb_lists = degree_comb_lists(d, m)
    coef_list = []
    for cb in all_comb_lists:
        point = []
        for j in range(m):
            # linear transformation to normalize the box to I=[0,1]^m
            # lower bound of the j-th component
            alpha_j = np.float64(box[j][0])
            # upper bound of the j-th component
            beta_j = np.float64(box[j][1])
            point.append((beta_j-alpha_j)*(cb[j]/d[j])+alpha_j)
        coef = f(np.array(point, dtype=np.float64))[output_index]
        for j in range(m):
            k_j = cb[j]
            d_j = d[j]
            coef = coef*comb(d_j, k_j)
        coef_list.append(coef)
    return np.array(all_comb_lists), np.array(coef_list)


def point_shift_all(points, box, large_sample_times=False, shift_points=None):
    if not large_sample_times:
        new_points = np.ones_like(points)
        for idxState in range(points.shape[1]):
            alpha_j = np.float64(box[idxState][0])
            beta_j = np.float64(box[idxState][1])
            new_points[:, idxState] = (
                (points[:, idxState] - alpha_j) /
                (beta_j - alpha_j)
            )
        return new_points
    else:
        for idxState in range(points.shape[1]):
            alpha_j = np.float64(box[idxState][0])
            beta_j = np.float64(box[idxState][1])
            shift_points[:, idxState] = (
                (points[:, idxState] - alpha_j) /
                (beta_j - alpha_j)
            )
        return shift_points


step = -1


def bernstein_error_partition_cuda(
    nn,
    f,
    degree_bound,
    input_box,
    output_index,
    activation,
    filename,
):
    global step
    step += 1
    import error_bound
    eps = error_bound.error_bound
    input_dim = len(degree_bound)
    lips, network_output_range = lipschitz(
        nn,
        input_box,
        output_index,
        activation
    )

    distance_estimate = 0
    for idxState in range(input_dim):
        diff = np.diff(input_box[idxState])[0]
        if diff > distance_estimate:
            distance_estimate = diff

    LD_estimate = lips * distance_estimate * np.sqrt(input_dim)
    num_partition = int(np.ceil(LD_estimate // eps + 1))

    partition = [num_partition] * input_dim

    print('---------------' + filename + '-------------------')
    print('step: {}'.format(step))
    print('degree bound: {}'.format(degree_bound))
    print('number of partition: {}'.format(num_partition))
    print('Lipschitz constant: {}'.format(lips))

    all_comb_lists = sample_points_list(partition, input_dim)

    if isinstance(lips, np.ndarray):
        lips = lips[0]

    sample_times = (num_partition + 1)**input_dim
    large_sample_times = False
    if sample_times < 1e7:
        all_sample_points = np.zeros(
            ((num_partition + 1)**input_dim, input_dim),
            dtype=np.float32
        )
        all_shift_points = np.zeros(
            ((num_partition + 1)**input_dim, input_dim),
            dtype=np.float32
        )
    else:
        large_sample_times = True
        os.system('rm ./cach.hdf5')
        hdf5_store = h5py.File('./cach.hdf5', 'a')
        all_sample_points = hdf5_store.create_dataset(
            "all_sample_points",
            (sample_times, input_dim),
            compression='gzip'
        )
        all_shift_points = hdf5_store.create_dataset(
            "all_shift_points",
            (sample_times, input_dim),
            compression='gzip'
        )

    partition_box = np.zeros(input_dim, dtype=np.float64)
    for j in range(input_dim):
        alpha_j = np.float64(input_box[j][0])
        beta_j = np.float64(input_box[j][1])
        partition_box[j] = (beta_j - alpha_j) / num_partition

    for idxState in range(input_dim):
        alpha_j = np.float64(input_box[idxState][0])
        beta_j = np.float64(input_box[idxState][1])
        all_sample_points[:, idxState] = (
            (beta_j - alpha_j) *
            (points_list(all_comb_lists, idxState) / num_partition)
            + alpha_j
        )
        all_shift_points = point_shift_all(
            all_sample_points,
            input_box,
            large_sample_times,
            all_shift_points
        )
    if large_sample_times:
        hdf5_store.close()

    order_list, coeffs_list = nn_poly_approx_bernstein_cuda(
        f,
        degree_bound,
        input_box,
        output_index
    )
    poly = polyval(order_list, degree_bound, coeffs_list, 'test')

    if large_sample_times:
        with h5py.File('./cach.hdf5', 'r') as hdf5_store:
            all_sample_points = hdf5_store['all_sample_points'][:]
            all_shift_points = hdf5_store['all_shift_points'][:]

    if filename[:4] == 'nn_5' or filename[:4] == 'nn_2':
        batch_size = 1e5
    else:
        batch_size = 1e7
    batch_num = math.ceil(all_sample_points.shape[0] / batch_size)
    batch_idx = np.arange(1, batch_num) * batch_size
    batch_idx = batch_idx.astype(int)
    all_sample_points_batches = np.split(all_sample_points, batch_idx, axis=0)
    all_shift_points_batches = np.split(all_shift_points, batch_idx, axis=0)

    poly_results = np.zeros((all_sample_points.shape[0], 1))
    nn_results = np.zeros((all_sample_points.shape[0], 1))

    with U.make_session() as sess:
        sess.run(tf.global_variables_initializer())
        batch_pointer = 0
        print(
            'number of sampling points: {}'.format(all_sample_points.shape[0])
        )
        for sample_points, shift_points in zip(
            all_sample_points_batches,
            all_shift_points_batches
        ):
            batch_range = range(
                batch_pointer,
                batch_pointer + sample_points.shape[0]
            )
            print('batch_range: {}'.format(batch_range))
            poly_results[batch_range, :] = poly(
                sess,
                shift_points
            )
            nn_results[batch_range, :] = nn(
                sess,
                sample_points
            )
            batch_pointer += sample_points.shape[0]

    sample_error = np.max(np.absolute(poly_results[:, 0] - nn_results[:, 0]))
    error = sample_error + lips * LA.norm(partition_box)
    print('bp to nn error: {}'.format(error))

    return error


def lipschitz(NN_controller, network_input_box, output_index, activation):
    weight_all_layer = NN_controller.weights
    bias_all_layer = NN_controller.bias
    scale_factor = NN_controller.scale_factor

    activation_all_layer = NN_controller.activations

    layers = len(bias_all_layer)
    lips = 1
    input_range_layer = network_input_box
    for j in range(layers):
        if j < layers - 1:
            weight_j = weight_all_layer[j]
        else:
            weight_j = np.reshape(weight_all_layer[j][output_index], (1, -1))
        if j < layers - 1:
            bias_j = bias_all_layer[j]
        else:
            bias_j = np.reshape(bias_all_layer[j][output_index], (1, -1))
        lipschitz_j = lipschitz_layer(
            weight_j,
            bias_j,
            input_range_layer,
            activation_all_layer[j]
        )
        lips = lips * lipschitz_j
        input_range_layer, _ = output_range_layer(
            weight_j,
            bias_j,
            input_range_layer,
            activation_all_layer[j]
        )
    return lips * scale_factor, 0


def lipschitz_layer(weight, bias, input_range_layer, activation):
    neuron_dim = bias.shape[0]
    output_range_box, new_weight = output_range_layer(
        weight,
        bias,
        input_range_layer,
        activation
    )
    if activation == 'ReLU':
        return LA.norm(new_weight, 2)
    if activation == 'sigmoid':
        max_singular = 0
        for j in range(neuron_dim):
            range_j = output_range_box[j]
            if range_j[0] > 0.5:
                singular_j = range_j[0]*(1-range_j[0])
            elif range_j[1] < 0.5:
                singular_j = range_j[1]*(1-range_j[1])
            else:
                singular_j = np.array([0.25])
            if max_singular < singular_j:
                max_singular = singular_j
        return max_singular*LA.norm(weight, 2)
    if activation == 'tanh':
        max_singular = 0
        for j in range(neuron_dim):
            range_j = output_range_box[j]
            if range_j[0] > 0:
                singular_j = 1 - range_j[0]**2
            elif range_j[1] < 0:
                singular_j = 1 - range_j[1]**2
            else:
                singular_j = np.array([1])
            if max_singular < singular_j:
                max_singular = singular_j
        return max_singular*LA.norm(weight, 2)


def output_range_layer(weight, bias, input_range_layer, activation):
    # solving LPs
    neuron_dim = bias.shape[0]
    output_range_box = []
    new_weight = []
    for j in range(neuron_dim):
        # c: weight of the j-th dimension
        c = weight[j]
        c = c.transpose()
        b = bias[j]
        # compute the minimal input
        res_min = linprog(c, bounds=input_range_layer, options={"disp": False})
        input_j_min = res_min.fun + b
        # compute the minimal output
        if activation == 'ReLU':
            if input_j_min < 0:
                output_j_min = np.array([0])
            else:
                output_j_min = input_j_min
        if activation == 'sigmoid':
            output_j_min = 1/(1+np.exp(-input_j_min))
        if activation == 'tanh':
            output_j_min = 2/(1+np.exp(-2*input_j_min))-1
        # compute the maximal input
        res_max = linprog(
            -c,
            bounds=input_range_layer,
            options={"disp": False}
        )
        input_j_max = -res_max.fun + b
        # compute the maximal output
        if activation == 'ReLU':
            if input_j_max < 0:
                output_j_max = np.array([0])
            else:
                output_j_max = input_j_max
                new_weight.append(weight[j])
        if activation == 'sigmoid':
            output_j_max = 1/(1+np.exp(-input_j_max))
        if activation == 'tanh':
            output_j_max = 2/(1+np.exp(-2*input_j_max))-1
        output_range_box.append([output_j_min, output_j_max])
    return output_range_box, new_weight


def degree_comb_lists(d, m):
    # generate the degree combination list
    if m == 1:
        X = np.meshgrid(np.arange(d[0] + 1))
        return [tuple(row) for row in X]
    if m == 2:
        x = np.arange(d[0] + 1)
        y = np.arange(d[1] + 1)
        X, Y = np.meshgrid(x, y)
        grid = np.vstack((X.flatten(), Y.flatten()))
        return grid.T
    if m == 3:
        x = np.arange(d[0] + 1)
        y = np.arange(d[1] + 1)
        z = np.arange(d[2] + 1)
        X, Y, Z = np.meshgrid(x, y, z)
        grid = np.vstack((X.flatten(), Y.flatten(), Z.flatten()))
        return grid.T
    if m == 4:
        x = np.arange(d[0] + 1)
        y = np.arange(d[1] + 1)
        z = np.arange(d[2] + 1)
        h = np.arange(d[3] + 1)
        X, Y, Z, H = np.meshgrid(x, y, z, h)
        grid = np.vstack((X.flatten(), Y.flatten(), Z.flatten(), H.flatten()))
        return grid.T


def sample_points_list(d, m):
    # generate the degree combination list
    if m == 1:
        X = np.meshgrid(np.arange(d[0] + 1), sparse=True)
        return X
    if m == 2:
        x = np.arange(d[0] + 1)
        y = np.arange(d[1] + 1)
        grid = np.meshgrid(x, y, sparse=True)
        return grid
    if m == 3:
        x = np.arange(d[0] + 1)
        y = np.arange(d[1] + 1)
        z = np.arange(d[2] + 1)
        grid = np.meshgrid(x, y, z, sparse=True)
        return grid
    if m == 4:
        x = np.arange(d[0] + 1)
        y = np.arange(d[1] + 1)
        z = np.arange(d[2] + 1)
        h = np.arange(d[3] + 1)
        grid = np.meshgrid(x, y, z, h, sparse=True)
        return grid


def points_list(grid, axis):
    for idxDim in range(len(grid)):
        if idxDim != axis:
            grid[idxDim] *= 0
    points = sum(grid)
    return points.flatten()

    # degree_lists = []
    # for j in range(m):
    #     degree_lists.append(range(d[j]+1))
    # all_comb_lists = list(itertools.product(*degree_lists))
    # return all_comb_lists


def p2c(py_b):
    str_b = str(py_b)
    c_b = str_b.replace("**", "^")
    return c_b


def run(args):
    with open('error_bound.py', 'w') as f:
        f.write('error_bound = ' + str(args.error_bound))
    cmd = './' + args.filename
    os.system(cmd)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--filename', default='nn_13_sigmoid', type=str,
                        help='File name of the NNCS')
    parser.add_argument('--error_bound', default=1e-3, type=np.float64,
                        help='Required senstivity of the NNCS')
    args = parser.parse_args()
    run(args)

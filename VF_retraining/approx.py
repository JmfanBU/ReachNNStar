import time
import os
import argparse
import tensorflow as tf
import numpy as np
import ast
from uat import univAprox
from network import nn_config
from SA import simulated_annealing
import baselines.common.tf_util as U
from baselines.common.mpi_adam import MpiAdam
from mpi4py import MPI
dir = os.path.dirname(os.path.realpath(__file__))


if __name__ == '__main__':
    start_time = time.time()
    # we parse the potential arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('--input_dim', default=2, type=int,
                        help='Dimension of input')
    parser.add_argument('--output_dim', default=1, type=int,
                        help='Dimension of output')
    parser.add_argument('--hidden_dim', default=20, type=int,
                        help='Number of neurons')
    parser.add_argument('--layers', default=2, type=int,
                        help='Number of layers')
    parser.add_argument('--max_it', default=3000, type=int,
                        help='Maximum iteration times')
    parser.add_argument('--original_activation', default='RELU', type=str,
                        help='Activation function for original network')
    parser.add_argument('--activation', default='RELU', type=str,
                        help='Activation function for retrained network')
    parser.add_argument('--filename', default='neural_network_controller',
                        type=str, help='Network Parameters')
    parser.add_argument('--output_file', default='nn_relu', type=str,
                        help='Output File Name')
    parser.add_argument('--range', default=2, type=np.float,
                        help='Input Range')
    parser.add_argument('--Lipschitz', default=0.0, type=np.float,
                        help='Target Lipschiz constant value')
    parser.add_argument('--stepsize', default=1e-3, type=np.float,
                        help='Gradient descent stepsize')
    parser.add_argument('--scalar', default=1.0, type=np.float,
                        help='Scale factor of the nn output')
    parser.add_argument('--offset', default=0.0, type=np.float,
                        help='Offset of the nn output')
    parser.add_argument('--ua_scalar', default=1.0, type=np.float,
                        help='Scale factor of the ua output')
    parser.add_argument('--ua_offset', default=0.0, type=np.float,
                        help='Offset of the ua output')
    parser.add_argument('--regression_bound', default=1e-2, type=np.float,
                        help='Bound of regression error')
    parser.add_argument('--multi_range', default=None, type=str,
                        help='input range if multi-dim need to be specified')
    args = parser.parse_args()

    stepsize = args.stepsize

    same_dir_cnt = 0
    oppo_dir_cnt = 0

    # place input with specified dimension
    x = tf.placeholder(tf.float32, shape=[None, args.input_dim], name='x')

    # define the ground truth
    nn = nn_config(args.filename, args.original_activation)
    with tf.device('/device:GPU:0'):
        y_true = args.scalar * (nn(x) - args.offset)

        # build the computation graph
        with tf.variable_scope('Graph') as scope:
            # define approximator
            ua = univAprox(args.input_dim, args.output_dim,
                           args.hidden_dim, args.layers, args.activation,
                           scalar=args.ua_scalar, offset=args.ua_offset)
            y = args.ua_scalar * (ua(x) - args.ua_offset)

            # define the resulting loss and graph it using tensorboard
            scalar = args.ua_scalar

            # trainable variables
            trainable_vars = ua.vars

            # trainable variables count
            trainable_var_count = 0
            for vars in trainable_vars:
                count_in_var = 1
                for dim in vars.shape._dims:
                    count_in_var *= dim
                trainable_var_count += count_in_var

            with tf.variable_scope('Lossandgrads'):
                # losses
                regret_loss = tf.reduce_mean(tf.square(y - y_true))
                vf_loss = tf.square(scalar * ua.lipschitz_constant - args.Lipschitz)

                # gradients
                regret_lossandgrad = U.function([x], [regret_loss, U.flatgrad(regret_loss, trainable_vars)])
                vf_lossandgrad = U.function([x], [vf_loss, U.flatgrad(vf_loss, trainable_vars)])

            # define our train operation using Adam optimizer
            adam_all = MpiAdam(trainable_vars, epsilon=1e-3)

    # create a Saver to save UA afeter training
    saver = tf.train.Saver()
    with U.make_session() as sess:
        # create a SummaryWritter to save data for TensorBoard
        result_folder = dir + '/results/' + args.output_file + str(int(time.time()))
        sw = tf.summary.FileWriter(result_folder, sess.graph)

        print('Training our universal approximator')
        sess.run(tf.global_variables_initializer())

        # range
        if args.multi_range is not None:
            input_range = np.array(ast.literal_eval(args.multi_range))
        else:
            input_range = args.range
        # negative_input = -input_range
        # negative_input[0] = -0.2
        iters = 0
        current_loss = np.inf
        L = np.inf
        max_it = args.max_it
        eps = args.regression_bound
        sa_eps = simulated_annealing(T0=1)
        while iters < max_it or current_loss > args.regression_bound:
            # sampel input from range
            x_in = np.random.uniform(-input_range, input_range, [100000, args.input_dim])
            # and train on it
            current_loss, g_regret = regret_lossandgrad(x_in)
            current_vf_loss, g_vf = vf_lossandgrad(x_in)

            nn_g = g_regret[0:trainable_var_count]
            nn_g_vf = g_vf[0:trainable_var_count]

            comm = MPI.COMM_WORLD

            nn_g_reduced = np.zeros_like(nn_g)
            nn_g_vf_reduced = np.zeros_like(nn_g_vf)

            comm.Allreduce(nn_g, nn_g_reduced, op=MPI.SUM)
            nn_g_reduced /= comm.Get_size()

            comm.Allreduce(nn_g_vf, nn_g_vf_reduced, op=MPI.SUM)
            nn_g_vf_reduced /= comm.Get_size()

            final_gradient = np.zeros(len(g_regret)+len(g_vf) - trainable_var_count)
            final_gradient[trainable_var_count::] = np.concatenate((g_regret[trainable_var_count::],
                                                                    g_vf[trainable_var_count::]))

            nn_g_reduced_normalized = nn_g_reduced / np.linalg.norm(nn_g_reduced)
            nn_g_vf_reduced_normalized = nn_g_vf_reduced / np.linalg.norm(nn_g_vf_reduced)

            if np.isnan(nn_g_reduced_normalized).any():
                nn_g_reduced_normalized = nn_g_reduced
            if np.isnan(nn_g_vf_reduced_normalized).any():
                nn_g_vf_reduced_normalized = nn_g_vf_reduced

            dot = np.dot(nn_g_reduced_normalized, nn_g_vf_reduced_normalized)
            dot_norm = np.linalg.norm(nn_g_reduced_normalized) * np.linalg.norm(nn_g_vf_reduced_normalized)

            if (dot > 0):
                same_dir_cnt += 1
                bisector = nn_g_reduced_normalized + nn_g_vf_reduced_normalized
                bisector_normalized = bisector / np.linalg.norm(bisector)
                if np.isnan(bisector_normalized).any():
                    bisector_normalized = bisector

                target_dir = bisector_normalized

                final_gradient[0:trainable_var_count] = 0.5 * (np.dot(nn_g_reduced, target_dir) + np.dot(nn_g_vf_reduced, target_dir)) * target_dir

                adam_all.update(final_gradient, stepsize)
            else:
                if dot_norm == 0 or np.abs(dot + 1) < 1e-5:
                    print("Reach minimum Lipschitz constant")
                    break
                oppo_dir_cnt += 1
                eps_new = np.random.uniform(0.5*args.regression_bound, 1.5*args.regression_bound)
                eps = sa_eps.acceptance_function(eps, eps_new, current_loss)
                # if current_loss > np.random.uniform(0.5*args.regression_bound, 1.5*args.regression_bound):
                if current_loss > eps:
                    projection = np.dot(nn_g_reduced,
                                        nn_g_vf_reduced_normalized) * nn_g_vf_reduced_normalized

                    final_nn_gradient = nn_g_reduced - projection
                    final_gradient[0:trainable_var_count] = final_nn_gradient
                elif L > args.Lipschitz + 1e-1:
                    same_dir_cnt += 1
                    projection = np.dot(nn_g_reduced_normalized, nn_g_vf_reduced) * nn_g_reduced_normalized
                    final_nn_gradient = nn_g_vf_reduced - projection
                    final_gradient[0:trainable_var_count] = final_nn_gradient
                    max_it = max(iters + 10, max_it + 10)

                adam_all.update(final_gradient, stepsize)

            if (iters + 1) % 100 == 0:
                L = sess.run(scalar*ua.lipschitz_constant)
                print('batch: {}, regret_loss: {}, reduce_lipschitz numbers: {}, Lipschitz: {}'.format(iters + 1, current_loss, same_dir_cnt, L))
            iters += 1

        # Finally we save the graph to check that it looks like what we wanted
        saver.save(sess, result_folder + '/data.chkp')
        print("--- %s seconds ---" % (time.time() - start_time))

        # obtain the trained weights and bias
        weights = sess.run(ua.weights)
        bias = sess.run(ua.bias)
        # store parameters
        ua.store_params(weights, bias, args.output_file)

        # compute lipschitz constant
        L = sess.run(scalar*ua.lipschitz_constant)
        print('Lipschitz constant: {}'.format(L))

        # test values
        # x_test = np.array([[0, 0.01], [0.8629, 0.8812]])
        x_test = np.random.uniform(-input_range, input_range, [3, args.input_dim])
        test_y = sess.run(y, feed_dict={x: x_test})
        test_y_true = sess.run(y_true, feed_dict={x: x_test})
        print('Approximated value: {0}, true value: {1}'.format(test_y,
                                                                test_y_true))

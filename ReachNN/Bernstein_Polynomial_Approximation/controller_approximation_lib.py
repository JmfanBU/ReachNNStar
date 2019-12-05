import error_analysis as ea
import sympy as sp
import ast
from network_parser import nn_controller_details


def poly_approx_controller(
    d_str,
    box_str,
    output_index,
    activation,
    nerual_network
):
    d = ast.literal_eval(d_str)
    box = ast.literal_eval(box_str)
    output_i = ast.literal_eval(output_index)
    nn = nn_controller_details(nerual_network, activation, reuse=True)
    x = sp.symbols('x:' + str(nn.num_of_inputs))
    b, _, _ = ea.nn_poly_approx_bernstein(nn.controller, x, d, box, output_i)
    return ea.p2c(b)


def poly_approx_error(
    d_str,
    box_str,
    output_index,
    activation,
    nerual_network
):
    d = ast.literal_eval(d_str)
    box = ast.literal_eval(box_str)
    output_i = ast.literal_eval(output_index)
    nn = nn_controller_details(nerual_network, activation, reuse=True)
    error_bound = ea.bernstein_error_partition_cuda(
        nn,
        nn.controller,
        d,
        box,
        output_i,
        activation,
        nerual_network
    )
    return ea.p2c(error_bound)

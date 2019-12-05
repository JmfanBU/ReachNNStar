import numpy as np
from neuralnetwork import NN


def nn_controller_details(filename, activation, reuse=False):
    """
    Return weights and bias
    """
    filename = 'nn/' + filename

    with open(filename) as inputfile:
        lines = inputfile.readlines()
    length = len(lines)
    res = np.zeros(length)
    for i, text in enumerate(lines):
        res[i] = eval(text)

    # Set the controller
    NN_controller = NN(res, activation, reuse=reuse)

    return NN_controller

import numpy as np
from model import nn


def nn_config(filename, activation='RELU'):
    """
    Parse the network from text file
    """
    # obtain the trained parameters and assign the value to res
    with open('nn/' + filename) as inputfile:
        lines = inputfile.readlines()
    length = len(lines)
    res = np.zeros(length)
    for i, text in enumerate(lines):
        res[i] = eval(text)

    # set the neural network
    network = nn(res, activation)
    return network

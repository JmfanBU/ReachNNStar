import tensorflow as tf
import numpy as np
from numpy import cos, sin


class nn(object):
    """
    initialize neural network with pre-trained parameters
    Input: res (parameters)
    """
    def __init__(self, res, activation='RELU'):
        """
        parse the input parameters
        """
        # activation type
        activations = activation.split('_')
        if len(activations) > 1:
            self.activation = activations[0]
            self.last_layer_activation = activations[1]
        else:
            self.activation = activation
            self.last_layer_activation = None

        # parse structure of neural networks
        self.num_of_inputs = int(res[0])
        self.num_of_outputs = int(res[1])
        self.num_of_hidden_layers = int(res[2])
        self.network_structure = np.zeros(self.num_of_hidden_layers + 1,
                                          dtype=int)

        # pointer is current reading index
        self.pointer = 3

        # num of neurons of each layer
        for i in range(self.num_of_hidden_layers):
            self.network_structure[i] = int(res[self.pointer])
            self.pointer += 1

        # output layer
        self.network_structure[-1] = self.num_of_outputs

        # all values from the text file
        self.param = res

        # store the weights and bias in two lists
        self.parse_w_b()

    def parse_w_b(self):
        """
        Parse the input text file
        and store the weights and bias indexed by layer

        Generate: self.weights, self.bias
        """
        # initialize the weights and bias storage space
        self.weights = [None] * (self.num_of_hidden_layers + 1)
        self.bias = [None] * (self.num_of_hidden_layers + 1)

        # compute parameters of the input layer
        weight_matrix0 = np.zeros((self.network_structure[0],
                                   self.num_of_inputs))
        bias_0 = np.zeros(self.network_structure[0])

        for i in range(self.network_structure[0]):
            for j in range(self.num_of_inputs):
                weight_matrix0[i, j] = self.param[self.pointer]
                self.pointer += 1

            bias_0[i] = self.param[self.pointer]
            self.pointer += 1

        # store input layer parameters
        self.weights[0] = weight_matrix0
        self.bias[0] = bias_0

        # compute the hidden layers paramters
        for i in range(self.num_of_hidden_layers):
            weights = np.zeros((self.network_structure[i + 1],
                                self.network_structure[i]))
            bias = np.zeros(self.network_structure[i + 1])

            # read the weight matrix
            for j in range(self.network_structure[i + 1]):
                for k in range(self.network_structure[i]):
                    weights[j][k] = self.param[self.pointer]
                    self.pointer += 1
                bias[j] = self.param[self.pointer]
                self.pointer += 1

            # store parameters of each layer
            self.weights[i + 1] = weights
            self.bias[i + 1] = bias

    @property
    def lipschitz_constant(self):
        """
        this property should be used after variable initialization
        """
        # initialize L cosntant
        L = 1.0
        # multiply norm of weights in each layer
        for i, weight in enumerate(self.weights):
            L *= np.linalg.norm(weight, 2)
        return L

    def __call__(self, x, reuse=False, train=False):
        """
        function call to generate the output tensor
        """
        with tf.variable_scope('nn') as scope:
            if reuse:
                scope.reuse_variables()

            for i in range(self.num_of_hidden_layers):
                # linear transformation
                x = tf.layers.dense(x, self.network_structure[i],
                                    kernel_initializer=tf.constant_initializer(self.weights[i].T, verify_shape=True),
                                    bias_initializer=tf.constant_initializer(self.bias[i], verify_shape=True),
                                    trainable=train)
                # activate
                if self.activation == 'RELU':
                    x = tf.nn.relu(x)
                elif self.activation == 'TANH':
                    x = tf.nn.tanh(x)
                elif self.activation == 'SIGMOID':
                    x = tf.nn.sigmoid(x)

            # output layer
            x = tf.layers.dense(x, self.network_structure[self.num_of_hidden_layers],
                                kernel_initializer=tf.constant_initializer(self.weights[self.num_of_hidden_layers].T, verify_shape=True),
                                bias_initializer=tf.constant_initializer(self.bias[self.num_of_hidden_layers], verify_shape=True),
                                trainable=train)
            # activate
            if self.last_layer_activation is None:
                if self.activation == 'RELU':
                    x = tf.nn.relu(x)
                elif self.activation == 'SIGMOID':
                    x = tf.nn.sigmoid(x)
                elif self.activation == 'TANH':
                    x = tf.nn.tanh(x)
            else:
                if self.last_layer_activation == 'RELU':
                    x = tf.nn.relu(x)
                elif self.last_layer_activation == 'TANH':
                    x = tf.nn.tanh(x)
                elif self.last_layer_activation == 'SIGMOID':
                    x = tf.nn.sigmoid(x)

        return x

import numpy as np
import tensorflow as tf
import tf_util as U
from numpy import linalg as LA


class NN(object):
    """
    a neural network with relu activation function
    """
    def __init__(
        self,
        res=None,
        activation=None,
        keras=False,
        model=None,
        reuse=False
    ):
        if not keras:
            # activation type
            activations = activation.split('_')
            if len(activations) > 1:
                self.activation = activations[0]
                self.last_layer_activation = activations[1]
            else:
                self.activation = activation
                self.last_layer_activation = None
            # affine mapping of the output
            self.offset = res[-2]
            self.scale_factor = res[-1]

            # parse structure of neural networks
            self.num_of_inputs = int(res[0])
            self.num_of_outputs = int(res[1])
            self.num_of_hidden_layers = int(res[2])
            self.network_structure = np.zeros(self.num_of_hidden_layers + 1,
                                              dtype=int)

            self.activations = [self.activation] * (
                self.num_of_hidden_layers + 1
            )
            if self.last_layer_activation is not None:
                self.activations[-1] = self.last_layer_activation

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
            # self.weights
            # self.bias
            gpu_devices = U.get_available_gpus()
            if gpu_devices:
                device = gpu_devices[0]
            else:
                cpu_devices = U.get_available_cpus()
                device = cpu_devices[0]
            with tf.device(device):
                self.parse_w_b()
                self.x = tf.placeholder(
                    tf.float64, shape=[None, self.num_of_inputs], name='input'
                )
                self.y = self.tensorflow_representation(self.x, reuse=reuse)
        else:
            params = []
            self.weights = []
            self.bias = []
            for layer in model.layers:
                params.append(layer.get_weights())  # list of numpy arrays
            for param in params:
                if len(param) == 0:
                    continue
                else:
                    self.weights.append(param[0])
                    self.bias.append(param[1])
            self.model = model

    def keras_model(self, x):
        if self.model is not None:
            y = self.model.predict(x)
            return y

    def activate(self, x):
        """
        activation function
        """
        if self.activation == 'ReLU':
            x[x < 0] = 0
        elif self.activation == 'tanh':
            x = np.tanh(x)
        elif self.activation == 'sigmoid':
            x = 1/(1 + np.exp(-x))
        return x

    def last_layer_activate(self, x):
        """
        activation function
        """
        if self.last_layer_activation == 'ReLU':
            x[x < 0] = 0
        elif self.last_layer_activation == 'tanh':
            x = np.tanh(x)
        elif self.last_layer_activation == 'sigmoid':
            x = 1/(1 + np.exp(-x))
        return x

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
                                   self.num_of_inputs), dtype=np.float64)
        bias_0 = np.zeros((self.network_structure[0], 1), dtype=np.float64)

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
                                self.network_structure[i]), dtype=np.float64)
            bias = np.zeros((self.network_structure[i + 1], 1),
                            dtype=np.float64)

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

    def controller(self, x):
        """
        Input: state
        Output: control value after affine transformation
        """
        # transform the input
        length = x.shape[0]
        g = x.reshape([length, 1])

        # pass input through each layer
        for i in range(self.num_of_hidden_layers):
            # linear transformation
            g = self.weights[i] @ g
            g = g + self.bias[i]

            # activation
            g = self.activate(g)

        # output layer
        if self.last_layer_activation is not None:
            # linear transformation
            g = self.weights[self.num_of_hidden_layers] @ g
            g = g + self.bias[self.num_of_hidden_layers]

            # activation
            g = self.last_layer_activate(g)
        else:
            # linear transformation
            g = self.weights[self.num_of_hidden_layers] @ g
            g = g + self.bias[self.num_of_hidden_layers]

            # activation
            g = self.activate(g)

        # affine transformation of output
        y = g - self.offset
        y = y * self.scale_factor

        return y

    @property
    def lips(self):
        if self.activation == 'ReLU':
            scalar = 1
        elif self.activation == 'tanh':
            scalar = 1
        elif self.activation == 'sigmoid':
            scalar = 1/4
        # initialize L cosntant
        L = 1.0
        # multiply norm of weights in each layer
        for i, weight in enumerate(self.weights):
            L *= scalar * LA.norm(weight, 2)

        # activation function of output layer is not the same as other layers
        if self.last_layer_activation is not None:
            if self.activation == 'ReLU':
                L *= 1
            elif self.activation == 'tanh':
                L *= 1
            elif self.activation == 'sigmoid':
                L *= 1/4

        return L * self.scale_factor

    def tensorflow_representation(self, x, train=False, reuse=False):
        """
        function call to generate the output tensor
        """
        with tf.variable_scope('nn', reuse=tf.AUTO_REUSE):
            for i in range(self.num_of_hidden_layers):
                # linear transformation
                x = tf.layers.dense(
                    x, self.network_structure[i],
                    kernel_initializer=tf.constant_initializer(
                        self.weights[i].T, verify_shape=True
                    ),
                    bias_initializer=tf.constant_initializer(
                        self.bias[i][:, 0], verify_shape=True
                    ),
                    trainable=train
                )
                # activate
                if self.activation == 'ReLU':
                    x = tf.nn.relu(x)
                elif self.activation == 'tanh':
                    x = tf.nn.tanh(x)
                elif self.activation == 'sigmoid':
                    x = tf.nn.sigmoid(x)

            # output layer
            x = tf.layers.dense(
                x, self.network_structure[self.num_of_hidden_layers],
                kernel_initializer=tf.constant_initializer(
                    self.weights[self.num_of_hidden_layers].T,
                    verify_shape=True
                ),
                bias_initializer=tf.constant_initializer(
                    self.bias[self.num_of_hidden_layers][:, 0],
                    verify_shape=True
                ),
                trainable=train
            )
            # activate
            if self.last_layer_activation is None:
                if self.activation == 'ReLU':
                    x = tf.nn.relu(x)
                elif self.activation == 'sigmoid':
                    x = tf.nn.sigmoid(x)
                elif self.activation == 'tanh':
                    x = tf.nn.tanh(x)
            else:
                if self.last_layer_activation == 'ReLU':
                    x = tf.nn.relu(x)
                elif self.last_layer_activation == 'tanh':
                    x = tf.nn.tanh(x)
                elif self.last_layer_activation == 'sigmoid':
                    x = tf.nn.sigmoid(x)

            x = x - self.offset
            x *= self.scale_factor

            return x

    def __call__(self, sess, x_in):
        result = sess.run(self.y, feed_dict={self.x: x_in})
        return result

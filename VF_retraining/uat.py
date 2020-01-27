import tensorflow as tf


class univAprox(object):
    """
    neural network approximator
    """
    def __init__(
        self,
        input_dim,
        output_dim,
        hidden_dim=20,
        layers=2,
        activation='RELU',
        scalar=1,
        offset=0
    ):
        self.input_dim = input_dim
        self.output_dim = output_dim
        self.hidden_dim = hidden_dim
        self.layers = layers
        self.scalar = scalar
        self.offset = offset

        # activation type
        activations = activation.split('_')
        if len(activations) > 1:
            self.activation = activations[0]
            self.last_layer_activation = activations[1]
        else:
            self.activation = activation
            self.last_layer_activation = None

        self.weights_original = None

    def __call__(self, x):
        """
        neural network maps from input to output
        with specified layers and hidden dim
        """
        with tf.variable_scope('UniversalApproximator'):
            for i in range(self.layers):
                # linear transformation
                # x = tf.layers.dense(x, self.hidden_dim)
                if self.weights_original is None:
                    # x = tf.layers.dense(x, self.hidden_dim)
                    # x = tf.layers.dense(x, self.hidden_dim, kernel_initializer=tf.random_uniform_initializer(minval=-1, maxval=1))
                    x = tf.layers.dense(x, self.hidden_dim, kernel_initializer=tf.random_uniform_initializer(minval=-1.5, maxval=1.5))
                else:
                    x = tf.layers.dense(x, self.network_structure[i],
                                       kernel_initializer=tf.constant_initializer(self.weights_original[i].T, verify_shape=True),
                                       trainable=True)
                # activate
                if self.activation == 'RELU':
                    x = tf.nn.relu(x)
                elif self.activation == 'SIGMOID':
                    x = tf.nn.sigmoid(x)
                elif self.activation == 'TANH':
                    x = tf.nn.tanh(x)

            # output layer
            # x = tf.layers.dense(x, self.output_dim)
            # x = tf.layers.dense(x, self.output_dim, kernel_initializer=tf.random_uniform_initializer(minval=-1, maxval=1))
            x = tf.layers.dense(x, self.output_dim, kernel_initializer=tf.random_uniform_initializer(minval=-1.5, maxval=1.5))
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
                elif self.last_layer_activation == 'SIGMOID':
                    x = tf.nn.sigmoid(x)
                elif self.last_layer_activation == 'TANH':
                    x = tf.nn.tanh(x)

        return x

    @property
    def vars(self):
        return tf.get_collection(tf.GraphKeys.GLOBAL_VARIABLES, scope='Graph/UniversalApproximator')

    @property
    def weights(self):
        """
        this property should be used after variable initialization
        """
        weights_var = [v for v in tf.get_collection(tf.GraphKeys.TRAINABLE_VARIABLES, scope='Graph/UniversalApproximator') if v.name.endswith('kernel:0')]
        return weights_var

    @property
    def bias(self):
        """
        this property should be used after variable initialization
        """
        bias_var = [v for v in tf.get_collection(tf.GraphKeys.TRAINABLE_VARIABLES, scope='Graph/UniversalApproximator') if v.name.endswith('bias:0')]
        return bias_var

    @property
    def lipschitz_constant(self):
        """
        this property should be used after variable initialization
        """
        # Lipschitz
        if self.activation == 'RELU':
            scalar = 1
        elif self.activation == 'TANH':
            scalar = 1
        elif self.activation == 'SIGMOID':
            scalar = 1/4
        # initialize L cosntant
        L = tf.constant(1.0)
        # multiply norm of weights in each layer
        for i, weight in enumerate(self.weights):
            L *= scalar * tf.norm(weight, 2)

        # activation function of output layer is not the same as other layers
        if self.last_layer_activation is not None:
            if self.activation == 'RELU':
                L *= 1
            elif self.activation == 'TANH':
                L *= 1
            elif self.activation == 'SIGMOID':
                L *= 1/4

        return L

    def store_params(self, weights, bias, filename):
        """
        this property should be used after training
        """
        # write text file
        with open('nn_retrained/' + filename, 'w') as text_file:
            text_file.write('{}'.format(self.input_dim) + '\n')
            text_file.write('{}'.format(self.output_dim) + '\n')
            text_file.write('{}'.format(self.layers) + '\n')
            for i in range(self.layers):
                text_file.write('{}'.format(weights[i].shape[1]) + '\n')

            for k in range(len(weights)):
                for i in range(weights[k].shape[1]):
                    for j in range(weights[k].shape[0]):
                        text_file.write('{}'.format(weights[k].T[i, j]) + '\n')
                    text_file.write('{}'.format(bias[k].T[i]) + '\n')
            text_file.write('{}'.format(self.offset) + '\n')
            text_file.write('{}'.format(self.scalar) + '\n')

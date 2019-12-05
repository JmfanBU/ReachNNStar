import tensorflow as tf
import numpy as np
import tf_util as U


class polyval(object):
    def __init__(self, orders, d, coeffs, name=None):
        self.orders = orders
        self.d = d
        self.coeffs = coeffs

        self.input_dim = self.orders.shape[1]
        self.name = name

        gpu_devices = U.get_available_gpus()
        if gpu_devices:
            device = gpu_devices[0]
        else:
            cpu_devices = U.get_available_cpus()
            device = cpu_devices[0]

        with tf.device(device):
            self.declare_vars()

    def declare_vars(self):
        self.x = []
        for idxState in range(self.input_dim):
            self.x.append(
                tf.placeholder(
                    tf.float32, shape=[None, 1], name='input' + str(idxState)
                )
            )
        self.y = 0.0
        self.poly()

    def poly(self):
        for order_item, coeff in zip(self.orders, self.coeffs):
            item = 1.0
            for idxState in range(self.input_dim):
                item *= (
                    self.x[idxState]**order_item[idxState] *
                    (1.0 - self.x[idxState])**(
                        self.d[idxState] - order_item[idxState]
                    )
                )
            self.y = tf.add(self.y, coeff * item)

    def __call__(self, sess, x_in):
        feed_dict = {}
        for idxState in range(self.input_dim):
            feed_dict.update(
                {self.x[idxState]: x_in[:, idxState].reshape(-1, 1)}
            )
        result = sess.run(self.y, feed_dict=feed_dict)

        return result


if __name__ == '__main__':
    poly = polyval(np.array([[1, 2], [1, 2]]), [3, 3], [1, 0.1], 'test')
    with tf.Session() as sess:
        result = poly(sess, np.array([[0, 1], [1, 2], [2, 3]]))

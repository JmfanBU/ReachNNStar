import numpy as np


class simulated_annealing(object):
    def __init__(self, T0=1):
        self.T0 = 1
        self.k = 0

    @property
    def temperature(self):
        return max(0.01, min(1, 1 - 1e-3 * self.k/(1 + 1e-3 * self.k)))

    def acceptance_function(self, eps, eps_new, current_loss):
        if current_loss < eps_new:
            self.k += 1
            return eps_new
        else:
            self.k += 1
            T = self.temperature
            prob = np.exp(-0.02/T)
            if prob > np.random.uniform():
                return eps_new
            else:
                return eps

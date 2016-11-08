import numpy as np

class NeuralNet(object):
    """Class for neural network"""
    def __init__(self, hidden=1, output_units=2, hidden_units=3, inunits=3):
        self.hiddenLayers = hidden
        self.hiddenUnits = hidden_units
        self.inputUnits = inunits
        self.outUnits = output_units
        self.weightsLayer1 = [[0, 0, 0],
                              [0, 0, 0],
                              [0, 0, 0]]
        self.weightsLayer2 = [[0, 0, 0],
                              [0, 0, 0]]

    def propagate_forward(self, x):
        # three input units 1x3 and 3x3 gives 1x3 for the hidden
        # layer

        hidden_layer = np.dot(np.array(x), np.array(self.weightsLayer1))
        output_units = np.dot(np.array(hidden_layer), np.array(self.weightsLayer2))

        return output_units

    def sigmoid(z):
        return (1/(1 + exp(-z)))




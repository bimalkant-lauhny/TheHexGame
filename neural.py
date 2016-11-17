import numpy as np
import pandas as pd

def sigmoid(z):
    return 1/(1+np.exp(-z))

def sigmoidPrime(z):
    return np.exp(-z)/((1+np.exp(-z)**2)

class NeuralNetworks(object):
    """Class for Neural Network""" 
    def __init__(self):

        self.inputLayerSize = 36
        self.hiddenLayerSize = 5
        self.outputLayerSize = 1
        self.alpha = 0.5

        self.W1 = np.random.randn(self.inputLayerSize, 
            self.hiddenLayerSize)
        self.W2 = np.random.randn(self.hiddenLayerSize,
            self.outputLayerSize)

    def forward(self, X):

        self.Z2 = np.dot(X, self.W1)
        self.A2 = self.sigmoid(self.Z2)
        self.A3 = np.dot(self.A2, self.W2)
        yHat = self.sigmoid(self.Z3)
        self.yHat = yHat
        return yHat


    def backward(self, X, Y):

        self.yHat = self.forward(X)
        delta_k = np.multiply(-(y - self.yHat), self.sigmoidPrime(self.z3))
        dJdW2 = np.multiply(self.alpha,np.dot(self.A2.T, delta_k))

        delta2 = np.dot(delta_k, self.W2.T)*self.sigmoidPrime(self.Z 2)
        dJdW1 = np.multiply(self.alpha, np.dot(X.T, delta2))

        self.W1 = self.W1 + dJdW1
        self.W2 = self.W2 + dJdW2

    def computeCost(self, Y):
        return(0.5*np.sum((Y-self.yHat)**2))

    def train(self, X, Y, iterations=300):
        for iteration in iterations:
           self.forward(X)
           print("{}".format(self.computeCost(Y)))
           self.backward(X, Y) 

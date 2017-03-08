import numpy as np
import matplotlib.pyplot as plt


def guassRand(mu, sigma):
    base = 1 / np.sqrt(2 * np.pi)
    accept = False
    while not accept:
        x = np.random.random() * 10 - 5
        # print x
        u = np.random.rand()
        alpha = np.exp(- x*x / 2)
        if alpha >= u:
            accept = True
    return x * sigma + mu

MAX_POINT = 100000
points = []
mu = 0
sigma = 10

for i in range(MAX_POINT):
    points.append(guassRand(mu, sigma))

plt.hist(points, 50)
plt.show()

    
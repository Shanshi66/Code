import numpy as np
import random
from utils import loadTrainData, loadTestData

train_file = 'data/train.txt'
test_file = 'data/test.txt'

def ReLU(x):
    if x > 0: return x
    else: return 0

def GradReLU(x):
    if x > 0: return 1
    else: return 0

def Sigmoid(x):
    return 1 / (1 + np.exp(-x))

def Line(x):
    return x / 10

def GradLine(x):
    return 0.1

def GradSigmoid(x):
    return (1 - Sigmoid(x)) * Sigmoid(x)

def Grad(x):
    # return GradSigmoid(x)
    # return GradLine(x)
    return ReLU(x)

def Rand():
    return random.uniform(2, 5)

def RNNTrain(train_data):
    learning_rate = 0.005
    min_learning_rate = 0.0001
    max_epoch = 10
    b = Rand()
    c = Rand()
    v = Rand()
    u = [Rand(), Rand()]
    w = Rand()
    for epoch in range(max_epoch):
        print 'epoch %d' % (epoch + 1)
        random.shuffle(train_data)
        for sample in train_data:
            loss = 0
            seq_x = sample[0]
            seq_y = sample[1]
            output = []
            activation = []
            hidden = []
            h = 0
            total_t = len(seq_x)
            for t in range(total_t):
                x = seq_x[t]
                y = seq_y[t]
                a = b + w * h + u[0] * int(x[0]) + u[1] * int(x[1])
                h = ReLU(a)
                # h = Sigmoid(a)
                # h = Line(a)
                o = c + v * h
                lt = 0.5 *(o - int(y)) * (o - int(y))
                loss += lt
                output.append(o)
                activation.append(a)
                hidden.append(h)
            
            print loss
            

            grad_h = [0] * total_t
            for i in range(total_t)[::-1]:
                grad_h[i] = (output[i] - int(seq_y[i])) * v
                if i < total_t - 1:
                    grad_h[i] += grad_h[i + 1] * w * Grad(activation[i])

            grad_b = 0
            for i in range(total_t):
                grad_b += grad_h[i] * Grad(activation[i])
            
            grad_c = 0
            for i in range(total_t):
                grad_c += output[i] - int(seq_y[i])
            
            grad_w = 0
            for i in range(1, total_t):
                grad_w += grad_h[i] * Grad(activation[i]) * hidden[i - 1]
            
            grad_v= 0
            for i in range(total_t):
                grad_v += (output[i] - int(seq_y[i])) * hidden[i]

            grad_u0 = 0
            for i in range(total_t):
                grad_u0 += grad_h[i] * Grad(activation[i]) * int(seq_x[i][0])
            
            grad_u1 = 0
            for i in range(total_t):
                grad_u0 += grad_h[i] * Grad(activation[i]) * int(seq_x[i][1])

            b -= learning_rate * grad_b
            c -= learning_rate * grad_c
            w -= learning_rate * grad_w
            v -= learning_rate * grad_v
            u[0] -= learning_rate * grad_u0
            u[1] -= learning_rate * grad_u1
            
            learning_rate -= (learning_rate - min_learning_rate) / len(train_data) / max_epoch
            print b, c, w, u[0], u[1], learning_rate

def main():
    train_data = loadTrainData(train_file)
    test_data = loadTestData(test_file)
    RNNTrain(train_data)

if __name__ == '__main__':
    main()    
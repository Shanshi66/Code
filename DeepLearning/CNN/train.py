import numpy as np
from utils import loadImg, loadLabel
from basis import *
import sys

batch_size = 20
init_learning_rate = 0.1
min_learning_rate = 0.001
max_epoch = 2

def train(network, X, y, model_folder):
    learning_rate = init_learning_rate
    for epoch in range(max_epoch):
        # shuffle
        index = np.random.permutation(len(y))
        X = X[index]
        y = y[index]
        for i in range(0, len(y), batch_size):
            if i + batch_size >= len(y): bs = len(y) - i
            else: bs = batch_size
            total_loss = 0
            for j in range(bs):
                network.img_placeholder.feed(X[i + j])
                network.label_placeholder.feed(y[i + j])
                loss, result = network.forword()
                total_loss += loss
                network.backword(j)
            if bs > 1:
                network.averageGrad(bs)
            print 'epoch: %3d, %5d/%d, learning rate: %f, loss: %f' % \
                    (epoch + 1, i + batch_size, len(y), learning_rate, total_loss / bs) 
            # print total_loss / bs
            network.update(learning_rate)
            learning_rate -= (init_learning_rate - min_learning_rate) / max_epoch / len(y) * batch_size
            if learning_rate < min_learning_rate: learning_rate = min_learning_rate
            # print learning_rate
            # if i >= 10 * batch_size:
            #     break
        network.save(model_folder)

def test(network, X, y):
    right = 0
    for i in range(len(y)):
        network.img_placeholder.feed(X[i])
        network.label_placeholder.feed(y[i])
        loss, result = network.forword()
        if result == True: right += 1
    print 'Accuracy: %.2f' % (right * 1.0 / len(y))    

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'model folder is needed'
        exit()
    else:
        model_folder = sys.argv[1]
        if len(sys.argv) > 2:
            batch_size = int(sys.argv[2])
            init_learning_rate = float(sys.argv[3])
            max_epoch = int(sys.argv[4])
    
    train_img_file = 'data/train-images.idx3-ubyte'
    train_label_file = 'data/train-labels.idx1-ubyte'
    test_img_file = 'data/t10k-images.idx3-ubyte'
    test_label_file = 'data/t10k-labels.idx1-ubyte'
    config_file = '%s/config.txt' % model_folder

    train_img = loadImg(train_img_file)
    train_label = loadLabel(train_label_file)

    network = NetworkConstructor(train_img[0].shape, train_label[0].shape)
    network.initNetwork(config_file, model_folder)

    train(network, train_img, train_label, model_folder)

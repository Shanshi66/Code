import numpy as np
from utils import loadImg, loadLabel
from basis import NetworkConstructor
import sys

def test(network, X, y):
    right = 0
    total_loss = 0
    for i in range(len(y)):
        network.img_placeholder.feed(X[i])
        network.label_placeholder.feed(y[i])
        loss, result = network.forword()
        total_loss += loss
        if y[i][result] == 1: right += 1
    print 'Accuracy: %.2f' % (right * 1.0 / len(y))
    print 'Avarage loss: %f' % (total_loss / len(y))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'model folder is needed'
        exit()
    else:
        model_folder = sys.argv[1]
    
    test_img_file = 'data/t10k-images.idx3-ubyte'
    test_label_file = 'data/t10k-labels.idx1-ubyte'
    config_file = '%s/config.txt' % model_folder

    test_img = loadImg(test_img_file)
    test_label = loadLabel(test_label_file)

    network = NetworkConstructor(test_img[0].shape, test_label[0].shape)
    network.initNetwork(config_file, model_folder)

    test(network, test_img, test_label)

    


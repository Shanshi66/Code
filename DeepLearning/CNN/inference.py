import numpy as np
import os
from utils import loadImg, loadLabel, loadImgFromPic
from basis import NetworkConstructor
import matplotlib.image as mpimg
import sys

def inference(network, X):
    prediction = []
    for i in range(len(X)):
        network.img_placeholder.feed(X[i])
        loss, result = network.forword()
        prediction.append(result)
    return prediction

def saveImg(img_folder):
    test_img_file = 'data/t10k-images.idx3-ubyte'
    test_label_file = 'data/t10k-labels.idx1-ubyte'
    test_img = loadImg(test_img_file)
    test_label = loadLabel(test_label_file)
    label = []
    for i in range(10):
        img = test_img[i][0] * 255
        mpimg.imsave('%s/%d.png' % (img_folder, i), img, format = 'png')
        label.append(test_label[i])
    return label
    

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print 'Please try: python inference.py <model_folder> <img_folder>'
        exit()

    model_folder = sys.argv[1]
    img_folder = sys.argv[2]
    
    config_file = '%s/config.txt' % model_folder
    # label = saveImg(img_folder)

    index, img_data = loadImgFromPic(img_folder)

    network = NetworkConstructor(img_data[0].shape, (10, 1))
    network.initNetwork(config_file, model_folder)

    prediction = inference(network, img_data)
    for i in range(len(index)):
        print '%3s: %d' % (index[i], prediction[i])


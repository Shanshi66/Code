#coding=utf8

import numpy as np
import struct
import os
import matplotlib.image as mpimg

def loadImg(filename):
    print 'loading %s...' % filename
    with open(filename, 'rb') as f:
        buffer = f.read()
        head = struct.unpack_from('>IIII', buffer, 0)
        offset = struct.calcsize('>IIII')
        img_num = head[1]
        img_row = head[2]
        img_col = head[3]
        imgs = struct.unpack_from('>%dB' % (img_num * img_row * img_col), buffer, offset)
        imgs = np.reshape(imgs, [img_num, 1, img_row, img_col]) / 255.0
    return imgs

def loadLabel(filename):
    print 'loading %s...' % filename
    with open(filename, 'rb') as f:
        buffer = f.read()
        head = struct.unpack_from('>II', buffer, 0)
        offset = struct.calcsize('>II')
        img_num = head[1]
        labels = struct.unpack_from('>%dB' % img_num, buffer, offset)
        labels = np.reshape(labels, img_num)
        one_hot = np.zeros((img_num, 10))
        for i in range(len(labels)):
            one_hot[i, labels[i]] = 1
    return one_hot

def loadImgFromPic(folder):
    imgs = []
    index = []
    for pic in os.listdir(folder):
        index.append(pic)
        img = mpimg.imread('%s/%s' % (folder, pic))
        # print img[:,:,0]
        gray = np.dot(img[:,:,:3], [0.299, 0.587, 0.114])
        imgs.append(gray)
    imgs = np.array(imgs)
    return index, imgs    


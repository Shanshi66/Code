import numpy as np

def loadTrainData(train_file):
    data = []
    with open(train_file, 'r') as f:
        for line in f:
            line = line.split()
            map(lambda x: x[::-1], line)
            if len(line[2]) > len(line[0]): line[0] += '0' * (len(line[2]) - len(line[0]))
            if len(line[2]) > len(line[1]): line[1] += '0' * (len(line[2]) - len(line[1]))
            seq_x = zip(list(line[0]), list(line[1]))
            seq_y = list(line[2])
            data.append((seq_x, seq_y))
    return data

def loadTestData(test_file):
    data = []
    with open(test_file, 'r') as f:
        for line in f:
            line = line.split()
            map(lambda x: x[::-1], line)
            line[0] += '0'
            line[1] += '0'
            seq_x = zip(list(line[0]), list(line[1]))
            seq_y = list(line[2])
            data.append((seq_x, seq_y))
    return data
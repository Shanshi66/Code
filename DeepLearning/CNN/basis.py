import numpy as np
import os

class Operation:
    def __init__(self):
        pass
    
    def excute(self):
        pass
    
    def calcGrad(self):
        pass
    
    def initGrad(self):
        pass
    
    def update(self):
        pass

    def averageGrad(self):
        pass

# class Variable:
#     def __init__(self, shape, init_method = 'constant'):
#         if init_method == 'constant':
#             self.var = np.zero(shape) + 0.1
#         if init_method == 'random':
#             self.var = np.random.uniform(-5, 5, shape)

def Variable(shape, init_method = 'constant', model_path = None, parm_count = None):
    var = None
    if model_path:
        parm_path = '%s/%d.npy' % (model_path, parm_count)
        if os.path.exists(parm_path):
            var = np.load(parm_path)
            return var
    if init_method == 'constant':
        var = np.zeros(shape) + 0.1
    if init_method == 'random':
        var = np.random.uniform(-0.2, 0.2, shape)
    # print var
    return var

class Input(Operation):
    def __init__(self, data):
        self.data = data
    def feed(self, data):
        self.data = data
    def calcGrad(self, last_grad, sample_index):
        pass
    def averageGrad(self, bs):
        pass
    def update(self, learning_rate):
        pass
    def excute(self):
        return self.data

class Add(Operation):
    def __init__(self, args):
        self.arg1 = args[0]
        self.arg2 = args[1]
    
    def excute(self):
        self.output1 = self.arg1
        self.output2 = self.arg2
        if isinstance(self.arg1, Operation):
            self.output1 = self.arg1.excute()
        if isinstance(self.arg2, Operation):
            self.output2 = self.arg2.excute()
        # print self.output2
        # print 'Add: ', self.output1.shape, self.output2.shape
        x = self.output1 + self.output2
        return x
    
    def initGrad(self):
        self.total_grad1 = np.zeros(self.output1.shape)
        self.total_grad2 = np.zeros(self.output2.shape)
        self.grad1 = np.zeros(self.output1.shape)
        self.grad2 = np.zeros(self.output2.shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'Add grad'
        if sample_index == 0: self.initGrad()
        self.grad1 = last_grad
        self.grad2 = last_grad
        self.total_grad1 += self.grad1
        self.total_grad2 += self.grad2
        # print self.grad2
        # print sample_index
        if isinstance(self.arg1, Operation):
            self.arg1.calcGrad(self.grad1, sample_index)
        if isinstance(self.arg2, Operation):
            self.arg2.calcGrad(self.grad2, sample_index)
    
    def averageGrad(self, bs):
        self.total_grad1 = self.total_grad1 / bs
        self.total_grad2 = self.total_grad2 / bs
        # print self.total_grad2
    
    def update(self, learning_rate):
        self.output1 -= learning_rate * self.total_grad1
        self.output2 -= learning_rate * self.total_grad2
        # print self.output2

class Product(Operation):
    def __init__(self, args):
        self.arg1 = args[0]
        self.arg2 = args[1]
    
    def excute(self):
        self.output1 = self.arg1
        self.output2 = self.arg2
        if isinstance(self.arg1, Operation):
            self.output1 = self.arg1.excute()
        if isinstance(self.arg2, Operation):
            self.output2 = self.arg2.excute()
        # print 'Product: ', self.output1.shape, self.output2.shape
        # print self.output2
        x = np.dot(self.output1.T, self.output2)
        # print x
        return x
    
    def initGrad(self):
        self.total_grad1 = np.zeros(self.output1.shape)
        self.total_grad2 = np.zeros(self.output2.shape)
        self.grad1 = np.zeros(self.output1.shape)
        self.grad2 = np.zeros(self.output2.shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'Product grad'
        if sample_index == 0: self.initGrad()
        self.grad1 = np.dot(self.output2, last_grad.T)
        self.grad2 = np.dot(self.output1, last_grad)
        # print self.grad2
        self.total_grad1 += self.grad1
        self.total_grad2 += self.grad2
        # print self.output2.shape, last_grad.shape
        if isinstance(self.arg1, Operation):
            self.arg1.calcGrad(self.grad1, sample_index)
        if isinstance(self.arg2, Operation):
            self.arg2.calcGrad(self.grad2, sample_index)
    
    def averageGrad(self, bs):
        self.total_grad1 = self.total_grad1 / bs
        self.total_grad2 = self.total_grad2 / bs

    def update(self, learning_rate):
        self.output1 -= learning_rate * self.total_grad1
        self.output2 -= learning_rate * self.total_grad2

class Flatten(Operation):
    def __init__(self, args, shape):
        self.arg = args[0]
        self.origin_shape = shape
    
    def excute(self):
        self.output = self.arg
        if isinstance(self.arg, Operation):
            self.output = self.arg.excute()
        x = np.copy(self.output)
        # print 'Flatten: ', self.output.shape
        x = np.reshape(x, [np.prod(self.origin_shape), 1])
        return x
    
    def initGrad(self):
        self.total_grad = np.zeros(self.origin_shape)
        self.grad = np.zeros(self.origin_shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'Flatten grad'
        if sample_index == 0: self.initGrad()
        self.grad = np.reshape(last_grad, self.origin_shape)
        self.total_grad += self.grad
        if isinstance(self.arg, Operation):
            self.arg.calcGrad(self.grad, sample_index)
    
    def averageGrad(self, bs):
        # self.total_grad = self.total_grad / bs
        pass

    def update(self, learning_rate):
        pass

class ReLU(Operation):
    def __init__(self, args):
        self.arg = args[0]
    
    def excute(self):
        self.output = self.arg
        if isinstance(self.arg, Operation):
            self.output = self.arg.excute()
        # print 'ReLU: ', self.output.shape
        x = np.copy(self.output)
        x[self.output < 0] = 0
        return x
    
    def initGrad(self):
        self.total_grad = np.zeros(self.output.shape)
        self.grad = np.zeros(self.output.shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'ReLU grad'
        if sample_index == 0: self.initGrad()
        x = np.copy(self.output)
        x[x < 0] = 0
        x[x >= 0] = 1
        self.grad = np.multiply(last_grad, x)
        self.total_grad += self.grad
        if isinstance(self.arg, Operation):
            self.arg.calcGrad(self.grad, sample_index)
    
    def averageGrad(self, bs):
        # self.total_grad = self.total_grad / bs
        pass
    
    def update(self, learning_rate):
        # self.output -= learning_rate * self.total_grad
        pass

class Sigmoid(Operation):
    def __init__(self, args):
        self.arg = args[0]

    def sig(self, x):
        x[x > 7] = 7
        x[x <-7] = -7
        return 1.0 / (1.0 + np.exp(-x))
    
    def excute(self):
        self.output = self.arg
        if isinstance(self.arg, Operation):
            self.output = self.arg.excute()
        # print 'Sigmoid: ', self.output.shape
        return self.sig(self.output)
    
    def initGrad(self):
        self.total_grad = np.zeros(self.output.shape)
        self.grad = np.zeros(self.output.shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'Sigmoid grad'
        if sample_index == 0: self.initGrad()
        x = np.copy(self.output)
        self.grad = np.multiply(last_grad, self.sig(x) * (1 - self.sig(x)))
        self.total_grad += self.grad
        # print last_grad
        if isinstance(self.arg, Operation):
            self.arg.calcGrad(self.grad, sample_index)
    
    def averageGrad(self, bs):
        # self.total_grad = self.total_grad / bs
        pass
    def update(self, learning_rate):
        # self.output -= learning_rate * self.total_grad
        pass

class Loss(Operation):
    def __init__(self, args, y):
        self.arg = args[0]
        self.y = y
    
    def excute(self):
        self.output = self.arg
        if isinstance(self.arg, Operation):
            self.output = self.arg.excute()
        # print 'Loss: ', self.output.shape
        # print self.output     
        y_ = np.copy(self.output)
        y_ = y_ - np.min(y_)
        y_ = np.exp(y_)
        y_sum = np.sum(y_)
        y_ = y_ / y_sum
        self.y_ = y_
        label = np.argwhere(self.y_ == np.max(self.y_))[0][0]
        # print self.y.data
        loss = sum(-np.dot(self.y.data.T, np.log(self.y_)))
        return loss, label
    
    def initGrad(self):
        self.total_grad = np.zeros(self.output.shape)
        self.grad = np.zeros(self.output.shape)
    
    def calcGrad(self, sample_index):
        # print 'Loss grad'
        if sample_index == 0: self.initGrad()
        # print self.y
        index0 = np.argwhere(self.y.data == 0)
        self.grad[index0] = self.y_[index0]
        index1 = np.argwhere(self.y.data == 1)
        self.grad[index1] = self.y_[index1] - 1
        self.total_grad += self.grad
        if isinstance(self.arg, Operation):
            self.arg.calcGrad(self.grad, sample_index)
    
    def averageGrad(self, bs):
        # self.total_grad = self.total_grad / bs
        # print self.total_grad
        pass
    
    def update(self, learning_rate):
        # self.output -= learning_rate * self.total_grad
        pass

class Pooling(Operation):
    def __init__(self, args, shape, method):
        self.arg = args[0]
        self.shape = shape
        self.method = method
    
    def excute(self):
        self.output = self.arg
        if isinstance(self.arg, Operation):
            self.output = self.arg.excute()
        # print 'Pooling: ', self.output.shape
        x = None
        if self.method == 'Avg-Pooling':
            x = self.avgPooling()
        return x

    def avgPooling(self):
        origin_shape = self.output.shape
        x = np.zeros((origin_shape[0], origin_shape[1] / self.shape[0], origin_shape[2] / self.shape[1]))
        for chanel in range(x.shape[0]):
            for row in range(x.shape[1]):
                for col in range(x.shape[2]):
                    s = 0
                    for i in range(self.shape[0]):
                        for j in range(self.shape[1]):
                            s += self.output[chanel, row * self.shape[0] + i, col * self.shape[1] + j]
                    x[chanel, row, col] = s / self.shape[0] / self.shape[1]
        return x
    
    def initGrad(self):
        self.total_grad = np.zeros(self.output.shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'Pooling grad'
        if sample_index == 0: self.initGrad()
        self.grad = np.zeros(self.output.shape)
        for chanel in range(last_grad.shape[0]):
            for row in range(last_grad.shape[1]):
                for col in range(last_grad.shape[2]):
                    for i in range(self.shape[0]):
                        for j in range(self.shape[1]):
                            self.grad[chanel, row * self.shape[0] + i, col * self.shape[1] + j] = \
                                last_grad[chanel, row, col] / self.shape[0] / self.shape[1]
        self.total_grad += self.grad
        if isinstance(self.arg, Operation):
            self.arg.calcGrad(self.grad, sample_index)
    
    def averageGrad(self, bs):
        # self.total_grad = self.total_grad / bs
        pass
    
    def update(self, learning_rate):
        # self.output -= learning_rate * self.total_grad
        pass

class Conv(Operation):
    def __init__(self, args, stride):
        self.arg1 = args[0]
        self.arg2 = args[1]
        self.stride = stride
    
    def excute(self):
        self.img = self.arg1
        self.kernel = self.arg2
        if isinstance(self.arg1, Operation):
            self.img = self.arg1.excute()
        if isinstance(self.arg2, Operation):
            self.kernel = self.arg2.excute()
        # print 'Conv:'
        # print '\t', self.img.shape
        # print '\t', self.kernel.shape
        dims = (self.kernel.shape[1], 
                (self.img.shape[1] - self.kernel.shape[2]) / self.stride + 1,
                (self.img.shape[2] - self.kernel.shape[3]) / self.stride + 1)
        output = np.zeros(dims)
        for chanel1 in range(output.shape[0]):
            for row in range(output.shape[1]):
                for col in range(output.shape[2]):
                   for chanel2 in range(self.img.shape[0]):
                       for i in range(self.kernel.shape[2]):
                           for j in range(self.kernel.shape[3]):
                               output[chanel1, row, col] += \
                                self.img[chanel2, row * self.stride + i, col * self.stride + j] * \
                                self.kernel[chanel2, chanel1, i, j]  

        return output
    
    def initGrad(self):
        self.img_total_grad = np.zeros(self.img.shape)
        self.kernel_total_grad = np.zeros(self.kernel.shape)
    
    def calcGrad(self, last_grad, sample_index):
        # print 'Conv grad'
        if sample_index == 0: self.initGrad()
        self.img_grad = np.zeros(self.img.shape)
        self.kernel_grad = np.zeros(self.kernel.shape)
        self.calcImgGrad(last_grad)
        self.calcKernelGrad(last_grad)
        self.img_total_grad += self.img_grad
        self.kernel_total_grad += self.kernel_grad
        if isinstance(self.arg1, Operation):
            self.arg1.calcGrad(self.img_grad, sample_index)
        if isinstance(self.arg2, Operation):
            self.arg2.calcGrad(self.kernel_grad, sample_index)
    
    def averageGrad(self, bs):
        self.img_total_grad = self.img_total_grad / bs
        self.kernel_total_grad = self.kernel_total_grad / bs

    def update(self, learning_rate):
        self.img -= learning_rate * self.img_total_grad
        self.kernel -= learning_rate * self.kernel_total_grad

    def calcImgGrad(self, last_grad):
        # print 'Img grad'
        # print np.prod(last_grad.shape) * np.prod(self.kernel.shape) / self.kernel.shape[1]
        for chanel1 in range(last_grad.shape[0]):
            for row in range(last_grad.shape[1]):
                for col in range(last_grad.shape[2]):
                    for chanel2 in range(self.kernel.shape[0]):
                        for i in range(self.kernel.shape[2]):
                            for j in range(self.kernel.shape[3]):
                                self.img_grad[chanel2, row * self.stride + i, col * self.stride + j] += \
                                self.kernel[chanel2, chanel1, i, j] * last_grad[chanel1, row, col] 

    def calcKernelGrad(self, last_grad):
        # print 'Kernel grad'
        # print np.prod(self.kernel.shape) * last_grad.shape[1] * last_grad.shape[2]
        for chanel1 in range(self.kernel.shape[0]):
            for chanel2 in range(self.kernel.shape[1]):
                for row in range(self.kernel.shape[2]):
                    for col in range(self.kernel.shape[3]):
                        for i in range(last_grad.shape[1]):
                            for j in range(last_grad.shape[2]):
                                self.kernel_grad += last_grad[chanel2, i, j] * \
                                        self.img[chanel1, i * self.stride + row, j * self.stride + col]



class NetworkConstructor:
    def __init__(self, input_size, output_size):
        self.img_placeholder = Input(Variable(input_size))
        self.label_placeholder = Input(Variable(output_size))
        self.computation_graph = [self.img_placeholder]
        self.parm_list = []
    
    def loadNetworkStructrue(self, filename):
        config = []
        with open(filename, 'r') as f:
            for line in f:
                config.append(line.strip())
        return config
    
    def initNetwork(self, config_file, model_path = None):
        config = self.loadNetworkStructrue(config_file)
        last_dims = self.img_placeholder.data.shape
        parm_count = 0
        for line in config:
            line = line.split()
            # print line
            # print line[0], last_dims
            if line[0] == 'CONVOLUTION':
                k_rows = int(line[1])
                k_cols = int(line[2])
                stride = int(line[3])
                maps = int(line[4])
                K = Variable([last_dims[0], maps, k_rows, k_cols], 'random', model_path, parm_count)
                self.parm_list.append(K)
                parm_count += 1
                #b = Variable([maps], 'constant')
                op = Conv([self.computation_graph[-1], K], stride)
                # op2 = Add([op1, b])
                # ops_list.append(op1)
                self.computation_graph.append(op)
                last_dims = (maps, (last_dims[1] - k_rows) / stride + 1, (last_dims[2] - k_cols) / stride + 1)
            if line[0] == 'RELU':
                op = ReLU([self.computation_graph[-1]])
                self.computation_graph.append(op)
            if line[0] == 'POOLING':
                k_rows = int(line[1])
                k_cols = int(line[2])
                op = Pooling([self.computation_graph[-1]], (k_rows, k_cols), 'Avg-Pooling')
                self.computation_graph.append(op)
                last_dims = (maps, last_dims[1] / k_rows, last_dims[2] / k_cols)
            if line[0] == 'FLATTEN':
                op = Flatten([self.computation_graph[-1]], last_dims)
                self.computation_graph.append(op)
                last_dims = (np.prod(last_dims), 1)
            if line[0] == 'FULL':
                hidden = int(line[1])
                W = Variable([last_dims[0], hidden], 'random', model_path, parm_count)
                parm_count += 1
                # print W.shape
                b = Variable([hidden, 1], 'constant', model_path, parm_count)
                parm_count += 1
                self.parm_list.append(W)
                self.parm_list.append(b)
                op = Product([W, self.computation_graph[-1]])
                self.computation_graph.append(op)
                op = Add([op, b])
                self.computation_graph.append(op)
                last_dims = (hidden, 1)
            if line[0] == 'SIGMOID':
                op = Sigmoid([self.computation_graph[-1]])
                self.computation_graph.append(op)
            if line[0] == 'LOSS':
                op = Loss([self.computation_graph[-1]], self.label_placeholder)
                self.computation_graph.append(op)

    def forword(self):
        loss = self.computation_graph[-1].excute()
        return loss

    def backword(self, sample_index):
        self.computation_graph[-1].calcGrad(sample_index)

    def averageGrad(self, bs):
        for op in self.computation_graph:
            if isinstance(op, Operation):
                op.averageGrad(bs)

    def update(self, learning_rate):
        for op in self.computation_graph:
            if isinstance(op, Operation):
                op.update(learning_rate)

    def save(self, folder):
        for i in range(len(self.parm_list)):
            np.save('%s/%d.npy' % (folder, i), self.parm_list[i])

    
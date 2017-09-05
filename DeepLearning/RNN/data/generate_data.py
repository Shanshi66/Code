import random

def generate(filename, size):
    with open(filename, 'w') as f:
        for i in range(size):
            a = random.randint(0, 10000000)
            b = random.randint(0, 10000000)
            f.write('%d %d %d\n' % (a, b, a + b))

def main():
    generate('train.txt', 1000)
    generate('test.txt', 1000)

if __name__ == '__main__':
    main()
            
fibo = [1, 1]
def fibonacci(n):
    for i in range(2, n+1):
        fibo.append(fibo[i-1]+fibo[i-2])

if __name__ == '__main__':
    fibonacci(200)
    f = open('out.txt', 'w')
    for i in range(200):
        f.write('"%d",\n'%fibo[i+1])
    f.close()

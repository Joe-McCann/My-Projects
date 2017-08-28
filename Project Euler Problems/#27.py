import math

def isPrime(n):
    if(n<0):
        return False
    for i in range(3, math.ceil(math.sqrt(n)), 2):
        if n%i == 0:
            return False
    return True

def primeCycle(f):
    count = 0
    while isPrime(f(count)):
        count+=1
    return (count-2)

maximum = 0
mprod = 0
for i in range(-1000,1001):
    for j in range(-1000,1001):
        k = primeCycle(lambda x: x**2+i*x+j)
        if(maximum < k):
            maximum = k
            mprod = i * j
print(maximum, i, j, mprod)

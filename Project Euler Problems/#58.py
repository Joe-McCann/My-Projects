import importantFunctions as impf
import math
import time

def isPrime(n, primes):
    if math.sqrt(n) > primes[-1]:
        print("AHHHHHH BROKEN!!!!!!!!!!!!!")
        print(n)
        k = input()
        return True
    for p in primes:
        if p > math.sqrt(n):
            break
        if n%p == 0:
            return False
    return True
x = time.time()
primes = sorted(impf.generatePrimes(1000000))
i = 1
total = 1
spiralPrimes = []
while 1:
    a = [lambda x: 4*x**2-2*x+1, lambda x: 4*x**2+1, lambda x: 4*x**2+2*x+1]
    for j in range(3):
        n = a[j](i)
        if(isPrime(n, primes)):
            spiralPrimes.append(n)
    i += 1
    total+=4
    percent = len(spiralPrimes)/total*100
    #print(total, ":", percent)
    if percent < 10:
        break
print(time.time()-x, 2*i-1)

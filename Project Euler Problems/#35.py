import math
import time

def isPrime(x):
    for i in range(2,int(math.sqrt(x))+1):
        if x % i == 0:
            return False
    return True

def generateCycles(num):
    lst = [num]
    digits = [x for x in str(num)]
    for i in range(len(digits)-1):
        hold = digits.pop(0)
        digits.append(hold)
        lst.append(int("".join(digits)))
    return lst

print("Generating the primes..")
primes = [1]*1000001
primes[0]=0
primes[1]=0
start = time.time()
for i in range(2, 1000001):
    if primes[i]:
        primes[i]*=i
        for j in range(i*2, 1000001, i):
            primes[j]=0
onlyPrimes = list(set(primes))
onlyPrimes.pop(0)
circularPrimes = []
print("Checking cycles...")
for prime in onlyPrimes:
    flag = True
    for cycle in generateCycles(prime):
        if cycle > 1000000:
            flag = False
            break
        if primes[cycle]:
            continue
        else:
            flag = False
            break
    if flag:
        circularPrimes.append(prime)
print(len(circularPrimes))
print(circularPrimes)
    
        

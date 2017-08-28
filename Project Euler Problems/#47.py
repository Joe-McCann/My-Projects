'''
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
'''
import math
import importantFunctions as impf

def factorize(k, primes):
    factors = []
    i = 0
    while k > 1:
        if k%primes[i] == 0:
            factors.append(primes[i])
            while k%primes[i] == 0:
                k/=primes[i]
        i+=1
    return factors

primes = impf.generatePrimes(1000000)
lst = []
count = 0
start = 10000
print("Beginning the process of guessing", max(primes))
for i in range(start, max(primes)):
    facts = factorize(i,primes)
    if len(facts) == 4:
        lst.append((i,facts))
        count+=1
        if count == 4:
            for j in range(1,5):
                print(lst[j*-1])
            break
    else:
        count=0
print("Done")

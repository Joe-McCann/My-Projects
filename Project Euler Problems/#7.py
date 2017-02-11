import math
def isPrime(k):
    for i in range(2, int(math.sqrt(k))+1):
        if k % i == 0:
            return False
    return True

primes = [2]
cand = 3

while len(primes) != 10001:
    if isPrime(cand):
        primes.append(cand)
    cand += 2

print(primes[-1])

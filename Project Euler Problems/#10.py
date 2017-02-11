import math
def isPrime(k):
    for i in range(2, int(math.sqrt(k))+1):
        if k % i == 0:
            return False
    return True

sump = 0
for i in range(1, 12, 2):
    if i % 10001 == 0:
        print((i/2000000)*100, "%")
    if isPrime(i):
        sump+=i

print(sump)

import math

def factorize(k):
    count = 0
    for i in range(1, int(math.sqrt(k)) + 1):
        if k % i == 0 and i <= k/i:
            count += 1
    return count * 2

def getTriangleNumber(n):
    return (n*(n+1))/2

n = 1
k = factorize(getTriangleNumber(n))
while k <= 500:
    #print(getTriangleNumber(n), ":", k)
    n+=1
    k = factorize(getTriangleNumber(n))

print(getTriangleNumber(n), ":", k)
    
     

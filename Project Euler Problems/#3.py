import math

def findPrimeFactor(x):

    for i in range(2, int(math.sqrt(x))):
        if x%i == 0:
            return i

    return x

num = 600851475143
lst = []
k = 1

while num != 1:
    k = findPrimeFactor(num)
    print(k)
    num/=k
    lst.append(k)

print (lst, max(lst))
    

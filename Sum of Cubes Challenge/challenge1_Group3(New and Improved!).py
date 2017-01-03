import time
import cmath
import math

#A Joe and Vai production

def sumOfCubes(k):
    bound = math.ceil(k**(1.0/3.0))
    bound2 = int(((k-1)/2)**(1.0/3.0))+1
    count = 0
    for x in range(1,bound2):
        count += int((k - 2*(x**3))**(1.0/3.0))

    for x in range(1, bound-2):
        for y in range(x+1, int((k-(x**3))**(1.0/3.0))):
            t = cmath.polar((k-(x**3)-(y**3))**(1.0/3.0))
            for z in range(y+1,(int(t[0])+2)*((-1)**int(t[1]))):
                if (x**3+y**3+z**3) <= k:
                    count += 1
    return count

x = time.time()
print (sumOfCubes(1000000), (time.time() - x), "seconds")


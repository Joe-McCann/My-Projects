import importantFunctions as impf
import math

def addFractions(frac1, frac2):
    num = [frac1[1]*frac2[0]+frac2[1]*frac1[0], frac1[1]*frac2[1]]
    k = impf.euclidAlgorithm(num[0], num[1])
    return [num[0]//k, num[1]//k]

one = [1, 1]
n = [3, 2]
count = 0
for i in range(1, 1000):
    n = addFractions(one, addFractions(one, n)[::-1])
    if int(math.log(n[0], 10)) > int(math.log(n[1], 10)):
        count+=1
print(count)


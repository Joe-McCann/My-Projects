import math

val = {0:0}
for i in range(1, 1001):
    for j in range(i, 1001):
        tot = i + j + math.sqrt(i**2+j**2)
        if tot.is_integer():
            #print(i, j)
            if tot in val:
                val[tot] += 1
            else:
                val[tot] = 1
            
maxi = 0
for key in val:
    if (val[key] > val[maxi])and(key<=1000):
        maxi = key
print(maxi)
        

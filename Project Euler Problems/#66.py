import math
def getDioNum(D):
    x = 2
    f = lambda x: ((x**2-1)/D)**.5
    y = ((f(x)))
    while not(y.is_integer()):
        x+=1
        y = (f(x))
    return x

rang = 1000
lst = []
for i in range(rang):
    if (math.sqrt(i+1).is_integer()):
        lst.append(0)
    else:
        lst.append(getDioNum(i+1))
    print(i+1, ":", lst[-1])

maxx = max(lst)
print("The largest value is", maxx, "occuring at D=", lst.index(maxx)+1)

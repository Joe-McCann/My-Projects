from functools import reduce

maxx = 0
for i in range(2, 100):
    if i%10==0:
        continue
    for j in range(2, 100):
        ds = reduce(lambda x,y: x+y, map(lambda x: int(x), list(str(i**j))))
        if ds > maxx:
            print(i, "^", j)
            maxx = ds
print(maxx)

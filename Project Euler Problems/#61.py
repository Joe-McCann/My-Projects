import importantFunctions as impf
import itertools
import time

def isCyclic(num1, num2):
    return (str(num1)[-2:] == str(num2)[:2])

def isCyclicSet(lst):
    if not isCyclic(lst[-1], lst[0]):
        return False
    for i in range(len(lst)-1):
        if not isCyclic(lst[i], lst[i+1]):
            return False
    return True

def hasPairs(num, lols):
    start = False
    end = False
    for lst in lols:
        for val in lst:
            if val == num:
                continue
            elif isCyclic(num, val):
                start = True
            elif isCyclic(val, num):
                end = True
            if start and end:
                return True
    return False
        

shapeNumFuncs = [lambda x: x*(x+1)//2, lambda x: x*x, lambda x: x*(3*x-1)//2,
             lambda x: x*(2*x-1), lambda x: x*(5*x-3)//2, lambda x: x*(3*x-2)]

shapeNums = [[],[],[],[],[],[]]

x = time.time()
for i in range(141):
    for j in range(len(shapeNums)):
        shapeNums[j].append(shapeNumFuncs[j](i))
for i in range(len(shapeNums)):
    shapeNums[i] = list(filter(lambda x: (x>999) and (x<10000), shapeNums[i]))
for j in range(15):
    for i in range(0, len(shapeNums)):
        hold = [lst for lst in shapeNums if lst != shapeNums[i]]
        for num in shapeNums[i]:
            if not hasPairs(num, hold):
                shapeNums[i].remove(num)
cycles = []
order = [0,1,2,3,4]
for perm in itertools.permutations(order):
    possibles = [[]]
    for hexNum in shapeNums[5]:
        for trinum in shapeNums[perm[0]]:
            if isCyclic(hexNum, trinum):
                possibles[0].append([hexNum, trinum])

    for i in range(1, 5):
        possibles.append([])
        for poss in possibles[-2]:
            for num in shapeNums[perm[i]]:
                if isCyclic(poss[-1], num):
                    possibles[-1].append([])
                    for j in poss:
                        possibles[-1][-1].append(j)
                    possibles[-1][-1].append(num)
    for cyc in possibles[-1]:
        cycles.append([])
        for i in cyc:
            cycles[-1].append(i)
cycles = list(filter(lambda x: isCyclicSet(x), cycles))
for cyc in cycles:
    print(cyc, "\nThe sum is:",  sum(cyc))
print("Completed in ", impf.formatTime(time.time()-x))

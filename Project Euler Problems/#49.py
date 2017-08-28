import importantFunctions as impf
import itertools
import time
def isPerm(s1, s2):
    if s1 == s2:
        return False
    lett = set(list(s1))
    for letter in lett:
        if s1.count(letter) != s2.count(letter):
            return False
    return True

def isArithmetic(lst):
    diff = abs(lst[1]-lst[0])
    for i in range(len(lst)-1):
        if abs(lst[i+1]-lst[i])!=diff:
            return False
    return True
x = time.time()
fdprimes = sorted(list(filter(lambda x: x>1000, impf.generatePrimes(10000))))
perms = []
i = 0
for prime in fdprimes:
    perms.append([prime])
    for otherPrime in fdprimes:
        if isPerm(str(prime), str(otherPrime)):
            perms[i].append(otherPrime)
            fdprimes.remove(otherPrime)
    i+=1
perms = list(filter(lambda x: len(x)>2, perms))
for lst in perms:
    for comb in itertools.combinations(lst, 3):
        if isArithmetic(list(comb)):
            print("".join([str(x) for x in comb]))
print(time.time()-x)


import importantFunctions as impf
import itertools
import time

def primePair(p1, p2):
    return [int("".join([str(p1), str(p2)])), int("".join([str(p2),str(p1)]))]

def validAddition(lst, prime, primes):
    for p in lst:
        pairs = primePair(p , prime)
        if impf.binarySearch(pairs[0], primes) == -1 or impf.binarySearch(pairs[1], primes) == -1:
            return False
    return True

x = time.time()
primes = sorted(impf.generatePrimes(100000000))
smallPrimes = sorted(impf.generatePrimes(10000))
print("Done generating primes")
validSets = [[]]
for i in range(len(smallPrimes)):
    for j in range(i, len(smallPrimes)):
        if validAddition([smallPrimes[i]], smallPrimes[j], primes):
            validSets[0].append([smallPrimes[i], smallPrimes[j]])
print("Done in: ", time.time()-x)
print("The set of pairs contains: ", len(validSets[0]), "pairs")
for a in range(1,4):
    validSets.append([])
    for valset in validSets[a-1]:
        for j in smallPrimes:
            if j in valset:
                continue
            elif validAddition(valset, j, primes):
                validSets[a].append([])
                for val in valset:
                    validSets[a][-1].append(val)
                validSets[a][-1].append(j)
                validSets[a][-1].sort()
    validSets[a].sort()
    validSets[a] = list(validSets[a] for validSets[a],_ in itertools.groupby(validSets[a]))
    print("Done in: ", time.time()-x)
    print("The set of triplets contains: ", len(validSets[a]), "triplets")
for thing in validSets[-1]:
    print(thing)

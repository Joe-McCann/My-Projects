import importantFunctions as impf

def checkTruncPrime(x, lst):
    k = [i for i in str(x)]
    l = [i for i in str(x)]
    for i in range(len(k)-1):
        k.pop(0)
        l.pop()
        if (int("".join(k)) not in lst) or (int("".join(l)) not in lst):
            return False
    return True

limit = 1000000
primes = impf.generatePrimes(limit)
count = 0
tab = 0
for prime in primes:
    if checkTruncPrime(prime,primes):
        count += 1
        print(count-4, ":", prime)
        tab += prime
        if count == 15:
            print("Found them all")
            break
tab -= (2+3+5+7)
print("The sum of the ", count-4, "numbers I found is:", tab)

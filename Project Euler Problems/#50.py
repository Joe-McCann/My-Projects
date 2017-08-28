import importantFunctions as impf

primes = sorted(impf.generatePrimes(1000000))

maxx = 0
maxLen = 0
for i in range(len(primes)-1):
    rollingSum = primes[i]
    count = 1
    sumSet = [primes[i]]
    while rollingSum < primes[-1]:
        rollingSum+=primes[i+count]
        sumSet.append(primes[i+count])
        count+=1
        if impf.binarySearch(rollingSum, primes[i+count:])!= -1:
            if maxLen < len(sumSet):
                maxLen = len(sumSet)
                maxx = rollingSum
                print(maxx,len(sumSet))
                


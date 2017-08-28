import importantFunctions as impf
import itertools

for t in range(9, 0, -1):
    perms = list(map("".join, itertools.permutations("".join([str(x) for x in range(1,t+1)]), t)))
    hold = 0
    for i in reversed(perms):
        hold = i
        if(impf.isPrime(int(i))):
            print(i)
            break
        
    print("No primes at: ", hold, t)



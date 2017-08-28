'''############################################################################################################################
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
#############################################################################################################################'''

import importantFunctions as impf

primes = impf.generatePrimes(10000)
primes.remove(2)
doubles = [2*(i**2) for i in range(0, 10000)]
odds = [1 for i in range(1, primes[-1], 2)]
odds[0] = 0
for prime in primes:
    for square in doubles:
        try:
            odds[int(((prime+square)-1)/2)]=0
        except IndexError:
            continue

for i in range(len(odds)):
    if odds[i]:
        print(2*i+1)


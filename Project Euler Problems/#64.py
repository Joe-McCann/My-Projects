import math
import importantFunctions as impf

def cycleLength(lst, n):
    for i in range(1, len(lst)):
        key = lst[0:i]
        div = len(lst)//len(key)
        newPat = key*div
        if newPat == lst[:len(newPat)]:
            return key
    return False

def generateTermsOfPeriod(n, k=1):
    terms = [int(math.sqrt(n))]
    rational = [n, -terms[0]]
    denom = 1

    for i in range(k*n):
        num = denom
        denom = rational[0] - (rational[1]**2)
        gcd = impf.euclidAlgorithm(num, denom)
        num /= gcd
        denom /= gcd
        terms.append(int((math.sqrt(rational[0])+(rational[1]*-1))/denom))
        rational[1] *= -1
        rational[1] -= (terms[-1]*denom)
    return cycleLength(terms[1:], n)

#print(generateTermsOfPeriod(37))
squares = [x**2 for x in range(1, 101)]
odds = []
for i in range(2, 10001):
    if i in squares:
        continue   
    key = generateTermsOfPeriod(i, k=1)
    if len(key)%2 == 1:
        #print(i, key)
        odds.append(i)
print(len(odds))

#print("There are", odds, "odd periods")'''


import math
import itertools
import timeit

def addFractions(frac1, frac2):
    num = [frac1[1]*frac2[0]+frac2[1]*frac1[0], frac1[1]*frac2[1]]
    k = impf.euclidAlgorithm(num[0], num[1])
    return [num[0]//k, num[1]//k]

def cycleLength(lst, n):
    for i in range(1, len(lst)):
        key = lst[0:i]
        div = len(lst)//len(key)
        newPat = key*div
        if newPat == lst[:len(newPat)]:
            return key
    return False

def generateContFraction(n, k=1):
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

def isPermutation(s1, s2):
    if s1 == s2:
        return False
    lett = set(list(s1))
    for letter in lett:
        if s1.count(letter) != s2.count(letter):
            return False
    return True

def quickSort(array):
    less = []
    equal = []
    greater = []

    if len(array) > 1:
        pivot = array[0]
        for x in array:
            if x < pivot:
                less.append(x)
            if x == pivot:
                equal.append(x)
            if x > pivot:
                greater.append(x)
        # Don't forget to return something!
        return quickSort(less)+equal+quickSort(greater)  # Just use the + operator to join lists
    # Note that you want equal ^^^^^ not pivot
    else:  # You need to hande the part at the end of the recursion - when you only have one element in your array, just return the array.
        return array

def binarySearch(item, lst):
    if lst[0]>item or lst[-1]<item:
        return -1
    first = 0
    last = len(lst)
    while first < last:
        pos = int((first+last)/2)
        if lst[pos] > item:
            last = pos - 1
            continue
        elif lst[pos] < item:
            first = pos + 1
        else:
            return pos
    if lst[last] == item:
        return last
    else:
        return -1

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def generatePentNum(amount):
    return [int(n*(3*n-1)/2) for n in range(1, amount+1)]

def generateTriangNum(amount):
    return [int(n*(n+1)/2) for n in range(1, amount+1)]

def generateHexNum(amount):
    return [int(n*(2*n-1)) for n in range(1, amount+1)]

def isPandigital(string):
    if len(string) != 9:
        return False
    digits = "123456789"
    for digit in digits:
        if string.count(digit) != 1:
            return False
    return True

def generatePrimes(limit):
    primes = [1]*(limit+1)
    primes[0]=0
    primes[1]=0
    for i in range(2, (limit+1)):
        if primes[i]:
            primes[i]*=i
            for j in range(i*2, (limit+1), i):
                primes[j]=0
    onlyPrimes = list(set(primes))
    onlyPrimes.pop(0)
    return onlyPrimes

#Returns true if number is prime
def isPrime(k):
    for i in range(2, int(math.sqrt(k))+1):
        if k % i == 0:
            return False
    return True

def factorSum(k):
    summ = 0
    for i in range(1, int(math.sqrt(k))+1):
        if k % i == 0 and i != k/i:
            summ += (i + k/i)
        elif i == k/i:
            summ += i
    return summ - k

#Not my bars and stars code. Got from internet
def partitions(n, k):
    for c in itertools.combinations(range(n+k-1), k-1):
        yield [b-a-1 for a, b in zip((-1,)+c, c+(n+k-1,))]

def isPallindrome(string):
    return (string == string[::-1])

def formatTime(seconds):
    return str(seconds//3600)+" hours "+str((seconds%3600)//60)+" minutes "+str(seconds%60)+ " seconds"

def euclidAlgorithm(a, b):
    #if b>a:
    #    hold = a
    #    a = b
    #    b = a
    while b!=0:
        k = a%b
        a = b
        b = k
    return a


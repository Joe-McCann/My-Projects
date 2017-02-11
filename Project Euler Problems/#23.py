import math

def factorSum(k):
    summ = 0
    for i in range(1, int(math.sqrt(k))+1):
        if k % i == 0 and i != k/i:
            summ += (i + k/i)
        elif i == k/i:
            summ += i
    return summ - k

def generateAmiableNumbers():
    num = []
    for i in range(1, 28124):
        if factorSum(i) > i:
            num.append(i)
    return num

def sumOfList(lst, k):
    for i in range(len(lst)//2+1):
        if (k - lst[i]) in lst:
            return True
    return False

print("Generating the list of numbers...", end = " ")
num = generateAmiableNumbers()
print(factorSum(4))
print("Complete", "Beginning loop...", sep = "\n\n")
summ = 0
for i in range(1, 28124):
    if not sumOfList(num, i):
        summ += i
    if i % 100 == 0:
        print(i)
print(summ)


        




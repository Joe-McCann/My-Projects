import math

def factorSum(k):
    summ = 0
    for i in range(1, int(math.sqrt(k))+1):
        if k % i == 0:
            summ += (i + k/i)
    return summ - k

numbers = [0] * 10001
count = 0
for i in range(1, len(numbers)):
    numbers[i] = factorSum(i)
    if numbers[i] < 10000 and (i) == numbers[int(numbers[i])] and numbers[i] != i:
        print(numbers[i], i)
        count += numbers[i] + i
print(count)

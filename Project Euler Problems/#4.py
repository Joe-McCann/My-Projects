def isPallindrome(a):
    stra = str(a)
    index = -1
    for i in stra:
        if i != stra[index]:
            return False
        index -=1
    return True

biggest = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        if isPallindrome(i * j) and (i * j) > biggest:
            biggest = i * j

print(biggest)

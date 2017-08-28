def isPallindrome(string):
    return (string == string[::-1])

tab = 0
count = 0
for i in range(1, 1000000):
    if isPallindrome(str(i)) and isPallindrome(str(bin(i))[2:]):
        count+=1
        tab += i
print(count, tab)

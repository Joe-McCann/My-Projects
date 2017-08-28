import importantFunctions as impf

count = 0
for i in range(10, 10001):
    flag = True
    num = i+int(str(i)[::-1])
    for j in range(0,50):
        if impf.isPallindrome(str(num)):
            print(i, j, num)
            flag = False
            break
        else:
            num += int(str(num)[::-1])
    if flag:
        print(i, "THIS IS ONE")
        count+=1

print(count)
    

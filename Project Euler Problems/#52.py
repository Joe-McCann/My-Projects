import importantFunctions as impf

def numSixPerms(num):
    for i in range(2, 7):
        if not impf.isPermutation(str(num), str(num*i)):
            return False
    return True

count = 1
flag = False
while not flag:
    print(count)
    for i in range(10**count, 10**(count+1)//6):
        if numSixPerms(i):
            flag = True
            print(i)
            break
    count+=1
    

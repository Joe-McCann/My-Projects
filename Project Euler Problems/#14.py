def helper(lst, check):
    if len(lst) > check:
        if lst[int(check)] != 0:
            return True
        else:
            return False
    else:
        for i in range(len(lst), check + 1):
            lst.append(0)
    return False

def collatz(lst, numb):
    num = int(numb)
    if helper(lst, num):
        return lst[num]
    else:
        k = 0
        if num % 2 == 0:
            k = num / 2
        else:
            k = 3*num + 1
        steps = 1 + collatz(lst, k)
        lst[num] = steps
        return steps

def safeAndSlowCollatz(k):
    a = 0
    while k != 1:
        if k % 2 == 0:
            k /= 2
        else:
            k = 3*k + 1
        a += 1
    return a
        

biggest = 1
bigc = 1
for i in range(1, 1000000):
    if i % 10000 == 0:
        print (i / 1000000 * 100, "%")
    x = safeAndSlowCollatz(i)
    if x > bigc:
        biggest = i
        bigc = x

print(biggest, bigc)
        
    
            
        

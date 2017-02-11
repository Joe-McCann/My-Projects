def isDivisible(k):
    for i in range(2, 21):
        if k % i != 0:
            return False
        
    return True

num = 40

while not isDivisible(num):
    num += 20
    if num % 1000000 == 0:
        print(num)
    
print(num, isDivisible(num))


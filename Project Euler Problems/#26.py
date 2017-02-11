def cycleLength(k):
    dec = [10**len(str(k))]
    while 1:
        x = dec[-1]%k
        while x < k and x != 0:
            x *= 10
        if x in dec or x % k == 0:
            return len(dec)
        else:
            dec.append(x)
    
lst = []
for i in range(2,1000):
    lst.append(cycleLength(i))

print(lst.index(max(lst))+2, max(lst))

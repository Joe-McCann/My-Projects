import itertools

#Not my bars and stars code. Got from internet
def partitions(n, k):
    for c in itertools.combinations(range(n+k-1), k-1):
        yield [b-a-1 for a, b in zip((-1,)+c, c+(n+k-1,))]

def checkThirty(lst):
    num = 0
    for i in range(len(lst)):
        num += lst[i]*(i**5)
    num = str(num).zfill(7)
    for i in range(len(lst)):
        if num.count(str(i)) != lst[i]:
            return False
    if int(num) < 2:
        return False
    print(num)
    return int(num)

count = 0
for p in partitions(7, 10):
    x = checkThirty(p)
    if x:
        count+=x
print(count)


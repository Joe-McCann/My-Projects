import itertools

def checkQual(k):
    lst = [2,3,5,7,11,13,17]
    for i in range(len(k)-2):
        if int(k[i:i+3])%lst[i] != 0:
            return False
    return True

perms = list(map("".join, itertools.permutations("".join([str(x) for x in range(10)]))))

lst = []
tot = 0
for perm in perms:
    if checkQual(perm[1:]):
        print(perm)
        lst.append(perm)
        tot+=int(perm)
print(tot)
        

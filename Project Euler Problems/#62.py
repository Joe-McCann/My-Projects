import importantFunctions as impf
perms = {}
for i in range(1, 10000):
    k = "".join(sorted(str(i**3)))
    if k in perms:
        perms[k].append(i)
    else:
        perms[k] = [i]

for key in perms:
    if len(perms[key]) == 5:
        print(key, len(perms[key]), perms[key])
        

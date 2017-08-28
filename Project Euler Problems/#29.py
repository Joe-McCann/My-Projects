a = 100
b = 100
lst = []
for i in range(2, a+1):
    for j in range(2, b+1):
        lst.append(i**j)
lst = set(lst)
print(len(lst))

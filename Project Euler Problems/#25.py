fibbSet = [1,1]

while len(str(fibbSet[-1])) < 1000:
    fibbSet.append(fibbSet[-1] + fibbSet[-2])

print(len(fibbSet))

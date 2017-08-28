import importantFunctions as impf
def addFractions(frac1, frac2):
    num = [frac1[1]*frac2[0]+frac2[1]*frac1[0], frac1[1]*frac2[1]]
    k = impf.euclidAlgorithm(num[0], num[1])
    return [num[0]//k, num[1]//k]

first = 2
seq = [int(2*k/3+4/3) if k%3 == 1 else 1 for k in range(99)]
frac = addFractions([seq[-2], 1], [1, seq[-1]])
for i in range(len(seq)-3, -1, -1):
    frac = frac[::-1]
    frac = addFractions([seq[i], 1], frac)

frac = frac[::-1]
frac = addFractions([first, 1], frac)
summ = 0

for dig in str(frac[0]):
    summ += int(dig)
print(summ)

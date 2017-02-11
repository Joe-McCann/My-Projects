import itertools

godList = [''.join(p) for p in itertools.permutations("0123456789")]

print(godList[999999])

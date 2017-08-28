def spiralSum(n):
    seed = 1
    summ = 1
    length = 1
    while length < n:
        length += 2
        for i in range(4):
            print(seed)
            seed += (length - 1)
            summ += seed
    return summ

print(spiralSum(1001))

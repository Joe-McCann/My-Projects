import math

x = str(math.factorial(100))
count = 0

for i in x:
    count += int(i)

print(count)

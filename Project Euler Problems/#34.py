import math

tab = 0
for i in range(10,2000001):
    hold = sum(map(lambda x: math.factorial(int(x)), [x for x in str(i)]))
    if hold == i:
        print(i)
        tab+=i
print("The sum of the values is: ", i)

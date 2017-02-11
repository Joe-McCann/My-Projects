fib1 = 1
fib2 = 2
count = 0

while fib2 <= 4000000:
    count += (fib1+1)%2*fib1 + (fib2+1)%2*fib2
    fib1 += fib2
    fib2 += fib1

print(count)

count = 1
nums = [2,3,4,5,6,7,8,9]
for i in range(1, 23):
    for num in nums:
        if len(str(num**i)) == i:
            count+=1
print(count)

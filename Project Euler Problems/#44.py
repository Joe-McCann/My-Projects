import time
def generatePentNum(amount):
    return [int(n*(3*n-1)/2) for n in range(1, amount+1)]

lst = generatePentNum(5000)
x = time.time()
ans = []
for i in range(0, len(lst)):
    print(i)
    for j in range(i, len(lst)):
        if (abs(lst[i]-lst[j]) in lst):
            if ((lst[i]+lst[j]) in lst):
                print("This is it: ", lst[i], lst[j], lst[i]+lst[j])
                print("Took: ", time.time()-x)
                ans.append(lst[i])
                break


print(ans)

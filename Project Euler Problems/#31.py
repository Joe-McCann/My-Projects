def coinSum(lst):
    tot = 0
    for i in range(len(lst[0])):
       tot += lst[0][i]*lst[1][i] 
    return tot
def addOneCoin(lst):
    lst[1][0] += 1
    count = 0
    while coinSum(lst) > 200:
        lst[1][count] = 0
        lst[1][count+1] += 1
        count+=1
    return lst
        

count = 1
lst = [[2,5,10,20,50,100,200],[0,0,0,0,0,0,0]]
while 1==1:
    lst = addOneCoin(lst)
    count+=1
    if lst[1][-1] == 1:
        break
print(count)
    
    

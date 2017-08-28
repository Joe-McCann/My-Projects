def oneOfEachDigit(string):
    if len(string) != 9:
        return False
    digits = "123456789"
    for digit in digits:
        if string.count(digit) != 1:
            return False
    return True

def addOneToArr(arr):
    arr[0] += 1
    for i in range(4):
        if arr[i] == 10:
            arr[i] = 1
            arr[i+1]+=1
        else:
            break
    return arr

arr = [1,1,1,1,1]
answers = []
summ = 0
while 1==1:
    prod = (arr[0]*10+arr[1])*(arr[2]*100+arr[3]*10+arr[4])
    if oneOfEachDigit("".join([str(x) for x in arr])+str(prod)):
        if prod not in answers:
            answers.append(prod)
    if arr.count(9) == 5:
        break
    arr = addOneToArr(arr)
arr = [1,1,1,1,1]
while 1==1:
    prod = (arr[0])*(arr[1]*1000+arr[2]*100+arr[3]*10+arr[4])
    if oneOfEachDigit("".join([str(x) for x in arr])+str(prod)):
        if prod not in answers:
            answers.append(prod)
    if arr.count(9) == 5:
        break
    arr = addOneToArr(arr)
print(answers)
print(sum(answers))


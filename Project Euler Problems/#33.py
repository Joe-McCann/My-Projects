def compareNumbers(x, y):
    for digit in x:
        if digit in y:
            a = x.replace(digit, "",1)
            b = y.replace(digit, "",1)
            if (int(x)/int(y)) == (int(a)/int(b)):
                return True
    return False

def comeUpWithPossibles(num):
    string = str(num)
    for k in range(len(string)):
        for i in range(2):
            for dig in "123456789":
                newNum = ["",""]
                newNum[i] = string[k]
                newNum[(i+1)%2] = dig
                newNum = "".join(newNum)
                #print(string,newNum,":",string[(i+1)%2],dig)
                if compareNumbers(string, newNum) and (string!=newNum) and (int(num)<int(newNum)):
                    return [string, newNum]
    return [False]

prod = [1, 1]
num = 11
while num < 100:
    hold = comeUpWithPossibles(num)
    if hold[0]:
        print(hold)
        prod[0]*=int(hold[0])
        prod[1]*=int(hold[1])
    num += 1
    if num % 10 == 0:
        num += 1
print(prod)
        


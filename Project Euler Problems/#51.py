import importantFunctions as impf

def primeFamily(string,primes):
    digits = ["0","1","2","3","4","5","6","7","8","9"]
    lst = []
    if string[0] == "*":
        digits.pop(0)
    for digit in digits:
        num = int(string.replace("*",digit))
        if impf.binarySearch(num, primes) != -1:
            lst.append(num)
    return lst

def generateNums(length, valid):
    numRep = [0]*length
    while numRep[0] < 10:
        numRep[-1] += 1
        hold = numRep[-1]//4
        numRep[-1]%=4
        for i in range(-2, length*-1, -1):
            numRep[i] += hold
            hold = numRep[i]//11
            numRep[i] %= 11
        numRep[0]+=hold
        if 10 not in numRep and numRep != 9:
            continue
        try:
            string = "".join([valid[0][numRep[0]], "".join([valid[1][numRep[x]] for x in range(1,length-1)]), valid[2][numRep[-1]]])
        except:
            break
        yield string
            

num = 1
primesDD = sorted(impf.generatePrimes(10000000))
print("Generated Primes")
validDigs = ["123456789*", "0123456789*", "1379"]
for i in range(5,8):
    print(i)
    for comb in generateNums(i, validDigs):
        lst = primeFamily(comb, primesDD)
        if len(lst)==8:
            print(lst)
            break
        

def numToWord(k):
    num = str(k)
    count = '';
#---------------------------------------#
    if len(num) == 1 or (len(num) >= 2 and num[-2] != '1'):
        if num[-1] == "1":
            count = 'one' + count
        elif num[-1] == '2':
            count = 'two' + count
        elif num[-1] == '3':
            count = 'three' + count
        elif num[-1] == '4':
            count = 'four' + count
        elif num[-1] == '5':
            count = 'five' + count
        elif num[-1] == '6':
            count = 'six' + count
        elif num[-1] == '7':
            count = 'seven' + count
        elif num[-1] == '8':
            count = 'eight' + count
        elif num[-1] == '9':
            count = 'nine' + count
    if len(num) <= 1:
        return count
#----------------------------------------#
    if num[-2] == '2':
        count = 'twenty' + count
    elif num[-2] == '3':
        count = 'thirty' + count
    elif num[-2] == '4':
        count = 'forty' + count
    elif num[-2] == '5':
        count = 'fifty' + count
    elif num[-2] == '6':
        count = 'sixty' + count
    elif num[-2] == '7':
        count = 'seventy' + count
    elif num[-2] == '8':
        count = 'eighty' + count
    elif num[-2] == '9':
        count = 'ninety' + count

#----------------------------------------#
    elif num[-2] == '1':
        if num[-1] == "1":
            count = 'eleven' + count
        elif num[-1] == '0':
            count = 'ten' + count
        elif num[-1] == '2':
            count = 'twelve' + count
        elif num[-1] == '3':
            count = 'thirteen' + count
        elif num[-1] == '4':
            count = 'fourteen' + count
        elif num[-1] == '5':
            count = 'fifteen' + count
        elif num[-1] == '6':
            count = 'sixteen' + count
        elif num[-1] == '7':
            count = 'seventeen' + count
        elif num[-1] == '8':
            count = 'eighteen' + count
        elif num[-1] == '9':
            count = 'nineteen' + count
    if len(num)<=2:
        return count
#-----------------------------------------#
    if num[-3] == "1":
        count = 'one' + 'hundred' + count
    elif num[-3] == '2':
        count = 'two' + 'hundred' + count
    elif num[-3] == '3':
        count = 'three' + 'hundred' + count
    elif num[-3] == '4':
        count = 'four' + 'hundred' + count
    elif num[-3] == '5':
        count = 'five' + 'hundred' + count
    elif num[-3] == '6':
        count = 'six' + 'hundred' + count
    elif num[-3] == '7':
        count = 'seven' + 'hundred' + count
    elif num[-3] == '8':
        count = 'eight' + 'hundred' + count
    elif num[-3] == '9':
        count = 'nine' + 'hundred' + count

    if num[-2] != '0' or num[-1] != '0':
        count += 'and'

    return count

summ = 0

for i in range(1, 1000):
    #print(i, ":", numToWord(i))
    summ+=len(numToWord(i))
summ+=len('onethousand')

print(summ)
        

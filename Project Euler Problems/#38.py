import importantFunctions as impf

def isPanProd(num):
    product = ""
    count = 1
    while len(product) < 9:
        product = "".join([product, str(num*count)])
        count += 1
    if len(product) != 9:
        return False
    elif impf.isPandigital(product):
        return int(product)
    else:
        return False

maxi = 0
for i in range(10000):
    k = isPanProd(i)
    if k:
        if k > maxi:
            maxi = k

print(maxi)

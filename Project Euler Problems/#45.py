import importantFunctions as impf

amount = 1000000
tri = impf.generateTriangNum(amount)
pent = impf.generatePentNum(amount)
hexa = impf.generateHexNum(amount)

for num in tri:
    if (num in pent) and (num in hexa):
        print(num)

import math

def isTriangularNumber(k):
    return (((math.sqrt(1+8*k)-1)/2).is_integer())

file = open("p042_words.txt", 'r')
content = file.read()
wordsList = [word.strip('"') for word in content.split(",")]

count = 0
for word in wordsList:
    tot = sum([ord(char)-64 for char in word])
    if isTriangularNumber(tot):
        count+=1
        print(word, tot)
print("Total triangular words is: ", count)

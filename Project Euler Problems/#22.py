import string
alphDict = {}
for i in range(len(string.ascii_uppercase)):
    alphDict[string.ascii_uppercase[i]] = i+1

def nameToNum(name):
    count = 0
    for i in name:
        count += alphDict[i]
    return count

file = open('names.txt', 'r')
names = file.read()
names = names.split(",")
names = sorted(names)
total = 0
for i in range(len(names)):
    names[i] = names[i].strip(string.punctuation)
for i in range(len(names)):
    total += nameToNum(names[i])*(i+1)

print(total)


#key = [103, 111, 99] or goc
file = open("p059_cipher.txt", 'r')
data = [int(x) for x in file.read().split(",")]
anchor = 97
end = 26
result = ""
cracked = False
key = []
for i in range(end):
    for j in range(end):
        for k in range(end):
            key = [anchor+i, anchor+j, anchor+k]
            result = ""
            for l in range(len(data)):
                result += chr(data[l]^key[l%3])
            words = result.split(" ")
            if "the" in words:
                cracked = True
                break
        if cracked:
            break
    if cracked:
        break

print(result)
print("".join([chr(x) for x in key]))
summ = 0
for i in result:
    summ += ord(i)
print(summ)


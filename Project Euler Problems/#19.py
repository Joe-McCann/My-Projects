def countSundays(days, year):
    first = []
    Sundays = 0
    if year%4 != 0 or year%400 == 0:
        first = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
    elif year%4 == 0:
        first = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
    for i in first:
        if days[i] == 0:
            Sundays += 1
    return Sundays

def generateYear(day):
    days = []
    for i in range(365):
        days.append((day + i)%7)
    return days

count = 0
day = 2
days = []

for i in range(1901, 2001):
    days = generateYear(day)
    t= countSundays(days, i)
    print(i, ":", t)
    count += t
    day = days[-1]
    if i % 4 == 0 and i % 400 != 0:
        day = (day + 1)%7

print(count)
  

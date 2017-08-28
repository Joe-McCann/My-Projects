import importantFunctions as impf

legend = {"2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "T":10, "J":11, "Q":12, "K":13, "A":14}

def getHighCard(hand):
    return max([legend[key] for key in hand[0]])

def getPair(hand):
    for card in set(hand[0]):
        if hand[0].count(card)==2:
            return legend[card]
    return False

def getTwoPair(hand):
    firstPair = getPair(hand)
    secondPair = False
    if firstPair:
        newlst = list(filter(lambda x: legend[x]!=firstPair, hand[0]))
        secondPair = getPair([newlst, 0])
        if secondPair:
            if(firstPair > secondPair):
                return chr(firstPair+97)+chr(secondPair+97)
            else:
                return chr(97+secondPair) + chr(97+firstPair)
    return "a"

def getThreeOfAKind(hand):
    for card in set(hand[0]):
        if hand[0].count(card)==3:
            return legend[card]
    return False

def getStraight(hand):
    new = list(map(lambda x: legend[x], hand[0]))
    mini = min(new)
    for i in range(len(new)):
        if mini + i not in new:
            return False
    return max(new)

def getFlush(hand):
    k = list(set(hand[1]))
    if len(k)==1:
        return 1
    else:
        return False

def getFullHouse(hand):
    two = getPair(hand)
    three = getThreeOfAKind(hand)
    if three and two:
        return chr(97+three)+ chr(97+two)
    else:
        return "a"

def getFourOfAKind(hand):
    for card in set(hand[0]):
        if hand[0].count(card)==4:
            return legend[card]
    return False

def getStraightFlush(hand):
    straight = getStraight(hand)
    flush = getFlush(hand)
    if straight and flush:
        return straight
    else:
        return False

def getRoyalFlush(hand):
    sF = getStraightFlush(hand)
    if sF != False:
        if sF == 14:
            return sF
        else:
            return False
    else:
        return False

def rankHand(hand):
    winCons = [getRoyalFlush, getStraightFlush, getFourOfAKind,
               getFullHouse, getFlush, getStraight,
               getThreeOfAKind, getTwoPair, getPair, getHighCard]
    rank = list(map(lambda x: x(hand), winCons))
    for i in range(len(rank)):
        if rank[i]==False:
            rank[i] = 0
    return rank

def compareHands(hand1, hand2):
    ranks = [rankHand(hand1), rankHand(hand2)]
    for i in range(len(ranks[0])):
            if ranks[0][i] == ranks[1][i]:
                continue
            elif ranks[0][i] > ranks[1][i]:
                return 0
            else:
                return 1

            

file = open("p054_poker.txt", 'r')
txt = file.read().split()
newTxt = [[[txt[0][0]],[txt[0][1]]]]
for i in range(1, len(txt)):
    if i % 5 == 0:
        newTxt.append([[],[]])
    newTxt[-1][0].append(txt[i][0])
    newTxt[-1][1].append(txt[i][1])
score = [0,0]
for i in range(0, len(newTxt), 2):
    score[compareHands(newTxt[i], newTxt[i+1])]+=1
print(score)
    

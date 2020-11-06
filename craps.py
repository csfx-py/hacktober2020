from random import *

def craps():
printIntro()
n=getInput()
winCount=simRoll(n)
printResults(n, winCount)


def printIntro():

print('This program simulates the popular casino game "craps." A player rolls a pair of normal six-sided dice.')
print('If the initial roll is a 2, 3, or 12, the player loses. If the initial roll is a 7 or 11, the player wins.')
print('Any other initial roll causes the player to "roll for point." The player keeps rolling the dice until either rolling')
print('a 7 or re-rerolling the value of the initial roll. If the player re-rolls the initial value before rolling a 7, it is a win.')
print('If the player rolls a 7 first, it is a loss.')
print('\nThis program simulates n games of craps and calculates the percent of games won.')


def getInput():

n=eval(input("Input the amount of games of craps to simulate: "))
return n


def simRoll(n):
rollCount=0
winCount=0
PointForRoll=0

while rollCount < n:

        rollCount=rollCount+1

        randomRoll=randrange(1,7) + randrange (1,7)

        if randomRoll == 2 or randomRoll == 3 or randomRoll == 12:
            winCount = winCount + 0

        if randomRoll == 7 or randomRoll == 11:
            winCount = winCount + 1

        else:

            while PointForRoll != 7 or PointForRoll != randomRoll:

                PointForRoll = randrange(1,7) + randrange(1,7)

                if PointForRoll == randomRoll:
                    winCount=winCount

                if PointForRoll == 7:
                    winCount=winCount+1

                return PointForRoll

return winCount


def printResults(n, winCount):

print('\nFor', n, 'games of craps simulated,', winCount, 'games were wins, giving a success rate of '+ str(100*(winCount/n)) + '%.')


if __name__ == '__main__': craps()

#prompt user to input change owed
change=round(float(input("Change owed: ")),2)

n=[0,0,0,0]

while (change>0):
    if (change>=.25):
        change-=.25
        n[0]+=1
    elif ((change >= .10) and (change < .25)):
        change = change - .10
        n[1]+= 1
        
    elif ((change >= .5) and (change < .10)):
        change = change - .5
        n[2]+=1
        
    else:
        change = change - .1
        n[3]+= 1
print("You have to give:\n%i 25 cent(s) \n%i 10 cent(s) \n%i 5 cent(s) \n%i 1 cent(s)",n[0],n[1],n[2],n[3])

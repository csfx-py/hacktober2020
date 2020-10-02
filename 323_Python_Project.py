
#Random Password_Generator
import random
import string

passw=""

#Define Set of Strings and Characters that password will contain
Number= string.digits
symbols = string.punctuation
all_letters= string.ascii_letters

#Declare set for 3 difficulty levels 
Easy = all_letters
Medium = all_letters + Number
Hard = all_letters+symbols+Number

#Taking Input from User for Length Of Password
print("Enter the length of the password you want:\n",end="")
len=int(input())

#Setting the number of generated passwords
print("Enter the number of passwords to be generated")
gen=int(input())



#Setting the Strength of Password
print("Enter the strength of the password you want to set\n")
print('''Enter 1 for Easy
Enter 2 for Medium
Enter 3 for Hard''')

choice=int(input())
for j in range(gen):

    if choice==1:
        for i in range(len):
            passw = random.choice(Easy)  #Choose a character from the EASY set of string
            print(passw,end="")
            
    elif choice==2:
        for i in range(len):
            passw=random.choice(Medium)  #Choose a character from the Medium set of string
            print(passw,end="")

    elif choice==3:
        for i in range(len):
            passw=random.choice(Hard)    #Choose a character from the Hard set of string
            print(passw,end="")

    else:
        print("Invalid Choice")
    print("\n")
    


    

    





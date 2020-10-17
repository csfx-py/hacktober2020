import secrets
import string


def gen_random_pass():
    all_random = string.ascii_letters + string.punctuation + string.digits #This is a complete list of upper, lower, digit and special charecters.
    random_password = secrets.choice(string.ascii_uppercase) #adding 1 uppercase alphabet
    random_password += secrets.choice(string.ascii_lowercase) #adding 1 lowercase alphabet
    random_password += secrets.choice(string.digits) #adding 1 digit
    random_password += secrets.choice(string.punctuation) #adding 1 special charecter

    length = int(input("Enter your password length: ")) #taking user input only in interger
    while length < 6: #checking is user input is less then 6
        print('A good password length should be equal to and greater then 6.')
        length = input("Enter your password length: ")
        length = int(length)

    length = length-4
    for i in range(length):
        random_password += secrets.choice(all_random)

    print("Your Random Password is : " + random_password)


gen_random_pass()

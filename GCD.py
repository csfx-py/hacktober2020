#find GCD of two Numbers using Recursion
def gcd(num1,num2):
    if(num2==0):
        return num1
    else:
        return gcd(num2,num1%num2)
num1=60
num2=48
GCD=gcd(num1,num2)
print("GCD:", GCD)

#Print the largest even integer which can be constructed using the given digits.
lis1=[]
lis2=[]
s=input()
lis1=s.split()
for i in lis1:
    if(int(i)%2==0):
        lis2.append(i)
if lis2==[]:
    print("No number possible.")
else:
    m=min(lis2)
    lis1.remove(m)
    lis1=sorted(lis1,reverse=True)
    lis1.extend(m)
    for i in lis1:
        print(i,end="")

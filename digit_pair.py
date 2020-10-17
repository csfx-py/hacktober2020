
Solution
def dig(n):
    s,l=9,0
    while(n):
        r=n%10
        if(s>r):
            s=r
        if(l<r):
            l=r
        n=n//10
    return [s,l]
  
def pair(t):
    if(t==2):
        return 1
    if(t>2):
        return 2
    return 0
      
n=int(input())
array=list(map(int,input().split()))
even=[]
odd=[]
for i in range(n):
    t=dig(array[i])
    s,l=t[0],t[1]
    l*=11
    s*=7
    array[i]=(l+s)%100
    
even=[0]*10
odd=[0]*10
for i in range(n):
    t=array[i]//10
    if (i+1)%2==0:
        even[t]+=1
    else:
        odd[t]+=1

c=[0]*10
for i in range(10):
    if(even[i]<=1) and odd[i]<=1:
        continue
    c[i]+=pair(even[i])+pair(odd[i])
    c[i]=min(2,c[i])
        
    #print(p,odd[i])
print(sum(c))

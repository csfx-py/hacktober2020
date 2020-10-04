#Author:Sourav Nanda
def bs(lst,low,high,mid):
    while val=n:
        for val in L:
            if val==lst[mid]:
                return val
            elif val<lst[mid]:
                high=mid
                mid-=1
                return val
            elif val>lst[mid]:
                 low=mid
                 mid+=1
            else:
                print('Not found')
                
L=[3,5,6,7,35,4,24,145,254,2,224,242,42]
n=int(input('Enter search item:'))
l=0
u=len(L)-1
mid=(l+u)//2
print('The number',n,'is found at',bs(L,l,u,mid))

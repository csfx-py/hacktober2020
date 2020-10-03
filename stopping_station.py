#There are n intermediate stations between two places A and B. 
# Find the number of ways in which a train can be made to stop at s of these intermediate stations
# so that no two stopping stations are consecutive.

#Input  : n = 16, s = 5
#Output : 792

def stopping_station( p, n): 
    num = 1
    dem = 1
    s = p 
  
    # selecting s positions 
    # out of n-s+1
    while p != 1: 
        dem *= p 
        p-=1
      
    t = n - s + 1
    while t != (n-2 * s + 1): 
        num *= t 
        t-=1
    if (n - s + 1) >= s: 
        return int(num/dem) 
    else: 
        return -1
  
num = stopping_station(4, 12) 
if num != -1: 
    print(num) 
else: 
    print("Not Possible") 
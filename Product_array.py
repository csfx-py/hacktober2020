##Product of an array excluding the current element

test = int(input())

def prod(size,arr):
    left_prod = [1]*size
    right_prod = [1]*size
    new_prod = [1]*size
    temp = 1
    
    for i in range(size):
        left_prod[i] = temp
        temp = temp * arr[i]
    
    temp = 1
    for i in range(size-1,-1,-1):
        right_prod[i] = temp
        temp = arr[i]*temp
        
    for i in range(size):
        new_prod[i] = left_prod[i]*right_prod[i]
        
    for i in range(size):
        print(new_prod[i],end=' ')

for i in range(test):
    arr_size = int(input())
    arr = [int(i) for i in input().strip().split()]
    prod(arr_size,arr)


## To find maximum subarray of size K 

def maximumSumSubarray (K,Arr,N):
    # code here 
    i = 0 
    j = 0
    maxx = float('-inf')
    summ = 0

    while j < N:
        summ += Arr[j]

        if (j-i+1) < K:
            j += 1

        elif (j-i+1) == K:
            maxx = max(summ,maxx)
            summ -= Arr[i]
            i += 1
            j += 1


    return maxx

# https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/the-electric-type/

# Electric Type- Data-Structures & Algorithms

N=int(raw_input())
arrA=map(int, raw_input().split())
diffs=[0]*N
done=set([])
prev=0
for i in xrange(N):
  if arrA[i] not in done:
    prev+=1
    done.add(arrA[i])
  diffs[i]=prev
done=set([])
res=0
for i in reversed(xrange(1,N)):
  if arrA[i] not in done:
    done.add(arrA[i])
    res+=diffs[i-1]
print res 
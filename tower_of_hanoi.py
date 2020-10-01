# Tower of hanoii


def solve(N,s,d,h):
  global cnt
  cnt += 1
  #print(cnt)
  if N == 1:
    print(f'Moving plate {N} from {s} to {d}')
    return
  
  solve(N-1,s,h,d)
  print(f'Moving plate {N} from {s} to {d}')
  solve(N-1,h,d,s)
  return cnt



N = int(input())
s,h,d,cnt = 1,2,3,0
print(solve(N,s,d,h))

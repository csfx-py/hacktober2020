cache = {}    
def fib(n):
    if n not in cache.keys():
        cache[n] = _fib(n)
    return cache[n]

def _fib(n):
    if n < 2:
        return n
    else:
        return fib(n-1) + fib(n-2)
        
n = int(input())
X = fib(n)
print(X)

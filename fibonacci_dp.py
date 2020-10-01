dp = {}

def fib(n):
	if n<2:
		return n
	
	if n in dp:
		return dp[n]
		
	ans = fib(n-1) + fib(n-2)
	dp[n] = ans
	
	return ans
	
n = int(input())
print(fib(n))

# Time Complexity: O(n)
# Space Complexity: O(n)

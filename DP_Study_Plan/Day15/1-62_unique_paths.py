class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        val = m+n-2 
        ans1 = 1 
        min_val = min(m-1,n-1)
        for i in range(min_val):
            ans1*=(m+n-2-i)
            ans1 = ans1//(i+1)
        return ans1
        

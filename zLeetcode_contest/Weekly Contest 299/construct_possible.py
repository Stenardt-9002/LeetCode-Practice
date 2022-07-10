class Solution:
	def TotalWays(self, N):
	    MOD = 1000000007
	    dp1 = [0]*(N+3)
	    dp1[1] = 1
	    for i1 in range(2,N+3):
	        dp1[i1] = (dp1[i1-1]+dp1[i1-2]);


	    return (int)((dp1[N+2]**2)%MOD) ;

	    pass


# print

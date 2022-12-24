# https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/




class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        max_arr = []
        for i in range(n):
            temp = [0]*i + [arr[i]]
            max_val = arr[i]
            for j in range(i+1 , n):
                max_val = max(max_val ,arr[j])
                temp.append(max_val)
            max_arr.append(temp)
        print(max_arr)
        # return 0 


        dp1 = []
        for _ in range(n):
            temp = [0]*n
            dp1.append(temp)


        for lenvar in range(1 , n):
            for start in range(0,n-lenvar):
                min_val = 99999
                for k in range(start , start+lenvar):
                    min_val = min(min_val,dp1[start][k]+dp1[k+1][start+lenvar]+(max_arr[start][k]*max_arr[k+1][start+lenvar]))

                dp1[start][start+lenvar] = min_val
        return dp1[0][n-1]

# Solution().mctFromLeafValues([1,2,3,4,5,4,3,-1,0])
        











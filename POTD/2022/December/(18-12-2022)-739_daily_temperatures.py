class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        if (n==1):
            return [0]
        ans = [0]*n
        stack_1 = [0]
        for i in range(1,n):
            while len(stack_1)>0 and temperatures[i]>temperatures[stack_1[-1]]:
                ans[stack_1[-1]] = i-stack_1[-1] 
                stack_1.pop()
            stack_1.append(i)
        return ans 
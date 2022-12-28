# https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/









class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        n = len(capacity)
        new_Array = [capacity[i]-rocks[i] for i in range(n)]
        new_Array.sort()
        ans = 0

        while (ans<n and additionalRocks-new_Array[ans]>=0):
            additionalRocks-=new_Array[ans]
            ans+=1
            
        return ans 
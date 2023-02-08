class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        min_sum = nums[0]
        max_sum = nums[0]
        cur_sum = 0
        cur_min = 0 
        final_sum = 0
        for i in nums:
            cur_sum = max(cur_sum+i ,i)
            max_sum = max(max_sum ,cur_sum)

            cur_min = min(cur_min+i , i)
            min_sum = min(cur_min , min_sum)

            final_sum+=i 
        if max_sum<=0:
            return max_sum
        return max(max_sum , final_sum-min_sum)
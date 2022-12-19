    # int rob(vector<int>& nums) {
    #     int n = nums.size();
    #     if(n==1)
    #         return nums[0];

    #     if(n==2)
    #         return max(nums[0],nums[1]);

    #     int prev = 0 , prev2 = 0 ;
    #     for (int i1 = 0; i1 < n; i1++)
    #     {
    #         int tmp = prev ;
    #         prev = max(prev2+nums[i1],prev);
    #         prev2 = tmp ;
    #     }
    #     return max(prev , prev2);
    # }


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if (n==1):
            return nums[0]
        if(n==2):
            return max(nums[0] , nums[1])

        prev2 = 0
        prev = 0
        for i in range(n):
            tmp = prev
            prev = max(prev2+nums[i] , prev)
            prev2 = tmp 
        return prev
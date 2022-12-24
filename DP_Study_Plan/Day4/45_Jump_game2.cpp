// https://leetcode.com/problems/jump-game-ii/?envType=study-plan&id=dynamic-programming-i




class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)    
            return 0 ;
        // if(nums[0]==0)
        int maxreach = nums[0],current_band_length = nums[0];
        int ans1 = 1;
        for(int i1=1;i1<n;i1++)
        {
           if(i1==n-1)
                return ans1 ;

            current_band_length--;
            maxreach = max(maxreach , i1+nums[i1]);
            if(current_band_length==0)
            {
                ans1++ ;
                // if(i1>maxreach)
                //     return -1 ;
                current_band_length = maxreach-i1 ;
            }

        }
        return 0;
    }
};



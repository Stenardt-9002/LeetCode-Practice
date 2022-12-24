class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)
            return true ;
        if(nums[0]==0)
            return false ;
        int i1,maxReach = nums[0] ;
        for(i1=1;i1<n;i1++)
        {
            if(i1>maxReach)
                return false ;
            if(maxReach>=n)
                return true;
            maxReach = max(maxReach , i1+nums[i1]);
        }
        return true ;  
    }
};
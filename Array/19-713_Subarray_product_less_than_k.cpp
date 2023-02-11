
// https://leetcode.com/problems/subarray-product-less-than-k/description/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



class Solution {
    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int ans = 0 ;
        if(k<=1)
            return 0 ;
        int n = nums.size();
        long long int prod = 1;
        int left = 0 ;
        for(int right = 0 ;right<n;right++)    
        {
            prod*=nums[right];
            while(prod>=k)
                prod = prod/nums[left++];

            ans+=(right-left+1);
        }
        return ans ;
    }
};
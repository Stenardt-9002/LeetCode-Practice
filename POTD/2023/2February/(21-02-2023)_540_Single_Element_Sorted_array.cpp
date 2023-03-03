


// https://leetcode.com/problems/single-element-in-a-sorted-array/description/












#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;














class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int low = 0 ,high = n-1;
        while(low<=high)
        {
            int mid = (high+low)>>1;
            bool ishalf = (mid-low)%2==0 ;
            if((mid>0)&&(nums[mid]==nums[mid-1]))
            {
                if(ishalf)
                    high = mid-2 ;
                else 
                    low = mid+1;
            }
            else if((mid<n-1)&&(nums[mid]==nums[mid+1]))  
            {
                if(ishalf)
                    low = mid+2 ;
                else 
                    high = mid-1;
            }
            else 
                return nums[mid];
        }
        return -1;
    }
};
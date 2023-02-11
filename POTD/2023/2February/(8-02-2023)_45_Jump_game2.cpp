


// https://leetcode.com/problems/jump-game-ii/










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
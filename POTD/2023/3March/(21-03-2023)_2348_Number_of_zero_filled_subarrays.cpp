// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

















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
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        long long int ans = 0 ;
        int first = 0 , second = 0 ;
        while(second<n)
            if(nums[second]==0)
            {
                second++ ;
                ans+=(second-first);
            }
            else 
                first = ++second ;
        
        // if(nums[n-1]!=0)
        //     ans+=(second-first);

        return ans ;     
    }
};



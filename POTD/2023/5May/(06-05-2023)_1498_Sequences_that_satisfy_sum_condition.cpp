// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/







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
    int numSubseq(vector<int>& nums, int target) 
    {
        int n = nums.size()    ;
        int ans = 0;
        sort(nums.begin(),nums.end());
        vector<int> get_power2(n,1);
        for(int i = 1 ; i<n;++i)
            get_power2[i] = (get_power2[i-1]*2)%MOD1;
        int first = 0 , second = n-1 ;
        while(first<=second)
        {
            if(nums[first]+nums[second]>target)
                second-- ;
            else 
            {
                int ids = second-first ;
                ans=((ans+get_power2[ids])%MOD1);
                first++ ;
            }
        }

        return ans ;
    }
};














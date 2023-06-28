// https://leetcode.com/problems/maximize-score-after-n-operations/












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
    int recursive_u(int index , int mask ,vector<int>&nums ,vector<int>&dp_mask , vector<int>&hash_gcd )
    {
        int n = nums.size();
        if(index>n/2)
            return 0 ;
        if(dp_mask[mask]!=-1)
            return dp_mask[mask];
        for(int i = 0 ; i< n ;i++)
        {
            if(mask&(1<<i))
                continue ;
            for(int j = i+1;j<n ; j++)
            {
                if(mask&(1<<j))
                    continue ;
                int newmask = (1<<i)|(1<<j)|mask;
                int ans = index*hash_gcd[i*17+j] +recursive_u(index+1 ,newmask , nums ,dp_mask , hash_gcd);
                dp_mask[mask] = max(dp_mask[mask],ans);
            }
        }
        return dp_mask[mask];
    }


    int maxScore(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>hash_gcd(400,0) ,dp1(1<<14,-1);
        
        for(int i =0 ; i<n ; i++)
            for(int j = 0;j<n ; j++)
                hash_gcd[17*i+j] = __gcd(nums[i],nums[j]);
        return recursive_u(1,0 , nums , dp1, hash_gcd);

    }
};











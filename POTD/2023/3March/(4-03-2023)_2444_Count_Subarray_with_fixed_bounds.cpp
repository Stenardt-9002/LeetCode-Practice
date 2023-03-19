// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
















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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        int n = nums.size() ;long long int ans = 0;
        long long int first = -1,min_index=-1,max_index=-1 ;
        for(int i = 0 ; i<n;++i)
        {
            if(nums[i]<minK || nums[i]>maxK)
                first = i; 
            else 
            {
                if(nums[i]==maxK)
                    max_index = i ;
                if(nums[i]==minK)
                    min_index = i ;
            }
            ans+=(max(0LL , min(max_index , min_index)-first));
        }
        return ans ;
    }
};





















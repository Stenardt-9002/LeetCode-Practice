// https://leetcode.com/problems/maximum-subarray/










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









int maxSubArray(vector<int>& nums) 
{
        int cur_sum = nums[0];
        int max_sum = cur_sum ;
        int n = nums.size();
        for (int i1 = 1; i1 < n; i1++)
        {
            cur_sum = max(cur_sum+nums[i1] , nums[i1]);
            max_sum = max(cur_sum,max_sum);
        }
        return max_sum ;
}





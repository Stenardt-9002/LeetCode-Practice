
// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan&id=dynamic-programming-i















#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






















class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> dp_set ;
        for(int num: nums)
            if(dp_set.empty() || dp_set[dp_set.size()-1]<num)
                dp_set.push_back(num);
            else 
            {
                auto pos = lower_bound(dp_set.begin(),dp_set.end() , num);
                *pos = num;
            }
        return dp_set.size();
    }
};
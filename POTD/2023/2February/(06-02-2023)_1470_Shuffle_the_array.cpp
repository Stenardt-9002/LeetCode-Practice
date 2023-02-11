
// https://leetcode.com/problems/shuffle-the-array/








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
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> ans ;
        for(int i = 0 ; i<n;i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans ;    
    }
};
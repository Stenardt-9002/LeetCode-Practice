// https://leetcode.com/problems/wiggle-subsequence/?envType=study-plan&id=dynamic-programming-i









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);














class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        int up = 1,down = 1;
        for (int i1 = 1; i1 < n; i1++)
        {
            if(nums[i1]>nums[i1-1]) up = down+1;
            else if(nums[i1]>nums[i1-1]) down = up+1;
        }
        return max(up,down) ;        
    }
};













// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<int> dp_inc(n,1)   ;
//         vector<int> dp_dec(n,1)   ;
//         int ans = 1;
//         for (int i1 = 0; i1 < n; i1++)
//         {
//             for (int j = i1 - 1; j >= 0; j--)
//             {
//                 if(nums[i1]>nums[j])
//                     dp_inc[i1] = max(dp_dec[j]+1,dp_inc[i1]);
//                 else if(nums[i1]<nums[j])
//                     dp_dec[i1] = max(dp_inc[j]+1,dp_dec[i1]);
//             }
//             ans = max({ans,dp_inc[i1] , dp_dec[i1]});
//         }
//         return ans ;        
//     }
// };
























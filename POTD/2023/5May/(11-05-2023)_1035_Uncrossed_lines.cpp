
// https://leetcode.com/problems/uncrossed-lines/






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
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size(),m = nums2.size();
        vector<vector<int>>dp1(n+1 , vector<int>(m+1, 0));
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=m ; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp1[i][j] = dp1[i-1][j-1]+1;
                else 
                    dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]);
            }
        }
        return dp1[n][m];
        
    }
};
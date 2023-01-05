// https://leetcode.com/problems/minimum-path-sum/description/












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
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size()    ;
        int m = grid[0].size() ;

        vector<vector<int>>dp1(n,vector<int>(m,0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp1[i][j] = grid[i][j];
        
        for (int i = 1; i < n; i++)
            dp1[i][0]+=dp1[i-1][0];
        
        for (int i = 1; i < m; i++)
            dp1[0][i]+=dp1[0][i-1];
        
            
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; ++j)
                dp1[i][j]+=min(dp1[i][j-1],dp1[i-1][j]);
            
        return dp1[n-1][m-1];
    }
};









































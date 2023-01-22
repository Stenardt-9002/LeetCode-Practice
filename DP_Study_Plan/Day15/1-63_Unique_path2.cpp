
// https://leetcode.com/problems/unique-paths/





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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(n==1 && m==1)    
        {
            if(obstacleGrid[0][0]==1)
                return 0 ;
            return 1;
        }
        if(obstacleGrid[0][0]||obstacleGrid[n-1][m-1])
            return 0;
        vector<vector<int>>dp1(n,vector<int>(m,0));
        dp1[0][0] = 1;
        for(int i = 1 ;i<m;i++)
            if(obstacleGrid[0][i]==1)
                dp1[0][i] = 0 ;
            else
                dp1[0][i] = dp1[0][i-1];

        for(int i = 1 ;i<n;i++)
            if(obstacleGrid[i][0]==1)
                dp1[i][0] = 0 ;
            else
                dp1[i][0] = dp1[i-1][0];


        for(int i = 1 ;i<n;++i)
            for(int j=1;j<m;++j)
                if(obstacleGrid[i][j]==1)
                    dp1[i][j] = 0;
                else
                    dp1[i][j] = dp1[i][j-1]+dp1[i-1][j]; 
            
        return dp1[n-1][m-1];
    }
};
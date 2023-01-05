// https://leetcode.com/problems/maximal-square/description/












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
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size() ;
        if(n==1 && m==1)
            return matrix[0][0]-'0';
        int ans1 = 0 ;
        vector<vector<int>>dp1(n,vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
            dp1[i][0] = matrix[i][0]-'0' ;
            ans1 = max(ans1 , dp1[i][0]);
        }

        for (int i = 0; i < m; i++)
        {
            dp1[0][i] = matrix[0][i]-'0' ;
            ans1 = max(ans1 , dp1[0][i]);
        }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
            {

                if(matrix[i][j]=='0')        
                    dp1[i][j] = 0 ;
                else 
                    dp1[i][j] = min({dp1[i-1][j],dp1[i][j-1],dp1[i-1][j-1]})+1;
                ans1 = max(ans1, dp1[i][j]);
            }
        return ans1*ans1 ;
    }
};












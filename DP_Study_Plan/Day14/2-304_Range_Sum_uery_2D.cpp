// https://leetcode.com/problems/range-sum-query-2d-immutable/












#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);














class NumMatrix {
public:
    vector<vector<int>>prefix_sum ;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size()    ;
        int m = matrix[0].size()    ;
        vector<vector<int>>ok(n,vector<int>(m,0));
        prefix_sum = ok ;
        prefix_sum[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++)
            prefix_sum[i][0]+=(prefix_sum[i-1][0]+matrix[i][0]);
        
        for (int i = 1; i < m; i++)
            prefix_sum[0][i]+=(prefix_sum[0][i-1]+matrix[0][i]);

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                prefix_sum[i][j] = matrix[i][j]+prefix_sum[i-1][j]+prefix_sum[i][j-1]-prefix_sum[i-1][j-1];    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        long long int ans = prefix_sum[row2][col2] ;
        if(row1>0)
            ans -=prefix_sum[row1-1][col2];
        if(col1>0)
            ans -=prefix_sum[row2][col1-1];
        if(row1>0 && col1>0)
            ans+=prefix_sum[row1-1][col1-1];    
        return ans ;
    }
};







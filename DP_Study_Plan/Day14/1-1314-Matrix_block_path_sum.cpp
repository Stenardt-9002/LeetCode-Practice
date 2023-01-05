

// https://leetcode.com/problems/matrix-block-sum/description/






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
    int get_val(int i , int j , int n , int m , vector<vector<int>>&prefix_sum)
    {
        if(i<0||j<0)
            return 0 ; 
        if(i>=n) i = n-1 ;
        if(j>=m) j = m-1 ;
        return prefix_sum[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int n = mat.size()    ;
        int m = mat[0].size() ;
        vector<vector<int>> prefix_sum(n,vector<int>(m,0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                prefix_sum[i][j] = mat[i][j] ;
                if(i>=1 && j>=1)
                    prefix_sum[i][j] -= prefix_sum[i-1][j-1] ;
                if(i>=1)
                    prefix_sum[i][j] += prefix_sum[i-1][j] ;
                if(j>=1)
                    prefix_sum[i][j] += prefix_sum[i][j-1] ;
            }
            
        vector<vector<int>>ans(n,vector<int>(m,0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = get_val(i+k,j+k,n,m,prefix_sum)+get_val(i-k-1,j-k-1,n,m,prefix_sum)-get_val(i-k-1,j+k,n,m,prefix_sum)-get_val(i+k,j-k-1,n,m,prefix_sum) ;

        return ans ;
    }
};
// https://leetcode.com/problems/number-of-islands/









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


void dfs_util(short srcx , short srcy ,short n , short m , vector<vector<char>>& grid )
{
    if(srcx<0||srcy<0||srcx>=n||srcy>=m||grid[srcx][srcy]=='0')
        return ;
    grid[srcx][srcy] = '0';
    dfs_util(srcx+1 , srcy ,n , m , grid);
    dfs_util(srcx , srcy+1 ,n , m , grid);
    dfs_util(srcx-1 , srcy ,n , m , grid);
    dfs_util(srcx , srcy-1 ,n , m , grid);
    return ;
}

int numIslands(vector<vector<char>>& grid) 
{
    short n = grid.size()    ;
    short m = grid[0].size();
    short componenets = 0 ;
    for (short i = 0; i < n; i++)
        for (short j = 0; j < m; j++)
            if(grid[i][j]=='1')
            {
                dfs_util(i,j,n,m,grid);
                ++componenets;
            }
    
    return componenets ;
}



























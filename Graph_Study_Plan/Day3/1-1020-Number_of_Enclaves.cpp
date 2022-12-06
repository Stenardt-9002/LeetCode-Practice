// https://leetcode.com/problems/number-of-enclaves/








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





void fill(short srcx , short srcy , short n , short m , vector<vector<int>> &graph)
{
    if(srcx<0 || srcy<0 || srcx>=n || srcy>=m || graph[srcx][srcy]==0)
        return  ;

    graph[srcx][srcy] = 0 ;
    fill(srcx+1 , srcy , n , m , graph);
    fill(srcx , srcy+1 , n , m , graph);
    fill(srcx-1 , srcy , n , m , graph);
    fill(srcx , srcy-1 , n , m , graph);
    return ;
}


int numEnclaves(vector<vector<int>>& grid) 
{
    short n = grid.size()    ;
    short m = grid[0].size()    ;
    short ans = 0 ;

    for (short i = 0; i < n; i++)
    {
        if(grid[i][0]==1)
            fill(i , 0 , n , m , grid);
        if(grid[i][m-1]==1)
            fill(i , m-1 , n , m , grid);
    }

    for (short i = 0; i < m; i++)
    {
        if(grid[0][i]==1)
            fill(0 , i , n , m , grid);
        if(grid[n-1][i]==1)
            fill(n-1,i  , n , m , grid);
    }

    for (short i = 0; i < n; i++)
        for (short j = 0; j < m; j++)
            ans+=(grid[i][j]==1);

    return ans ;    
}













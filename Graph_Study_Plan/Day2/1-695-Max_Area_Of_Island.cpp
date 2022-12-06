// https://leetcode.com/problems/max-area-of-island/?envType=study-plan&id=graph-i










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




void dfs_util(int i , int j ,int n ,int m ,vector<vector<int>>& grid ,int &current_dfs)
{
    if (i<0||j<0 || i>=n || j>=m || grid[i][j]==0)
        return ;


    grid[i][j] = 0;
    current_dfs++ ;
    dfs_util(i+1 , j , n , m , grid , current_dfs) ;
    dfs_util(i , j+1 , n , m , grid , current_dfs) ;
    dfs_util(i-1 , j , n , m , grid , current_dfs) ;
    dfs_util(i , j-1 , n , m , grid , current_dfs) ;

    return ; 

}



int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int n = grid.size()    ;
    int m = grid[0].size()    ;


    int ans = 0 ;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int current_dfs = 0;
            if(grid[i][j]==1)
                dfs_util(i , j , n , m , grid , current_dfs);
            ans = max(ans , current_dfs);
        }
        
    

    return ans ;
}

//3 ways 
// one above 
// bfs inside two for loops 
// dfs thsat returns int (current ans )
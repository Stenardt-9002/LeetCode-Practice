// https://leetcode.com/problems/max-area-of-island/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


bool allowed(int ix , int jy ,int m ,int n)
{
    return (ix>=0 && jy>=0 && ix<m && jy<n);
}


// int dfs_util(int ix , int jy ,int m ,int n ,vector<vector<int>> grid,vector<vector<bool>>&vsisted)
// {
//     int sum_1 = 0 ;
//     if(allowed(ix,jy,m,n)==false || vsisted[ix][jy]==true || grid[ix][jy]==0 )
//         return 0 ;
    
//     if(!vsisted[ix][jy] && grid[ix][jy]==1)
//         sum_1 = 1;

//     vsisted[ix][jy] = true ;

//     int a1 = dfs_util(ix-1,jy,m,n,grid,vsisted);
//     int b1 = dfs_util(ix,jy-1,m,n,grid,vsisted);
//     int c1 = dfs_util(ix,jy+1,m,n,grid,vsisted);
//     int d1 = dfs_util(ix+1,jy,m,n,grid,vsisted);

//     sum_1+=(a1+b1+c1+d1);
//     return sum_1;
// }

// int maxAreaOfIsland(vector<vector<int>>& grid) 
// {


//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<bool>>visisted(m,vector<bool>(n,false));
//     int max_ans = 0 ;
//     for (int i1 = 0; i1 < m; i1++)
//         for (int j1 = 0; j1 < n; j1++)
//             if(visisted[i1][j1]==false && grid[i1][j1]==1 )
//                 max_ans = max(max_ans , dfs_util(i1,j1,m,n,grid,visisted));
    

//     return max_ans ;
// }












int dfs_util(int ix , int jy ,int m ,int n ,vector<vector<int>> &grid)
{
    if(ix>=0 && jy>=0 && ix<m && jy<n && grid[ix][jy]==1)
    {
        grid[ix][jy] = 0 ;
        return 1 + dfs_util(ix-1,jy,m,n,grid)+ dfs_util(ix+1,jy,m,n,grid)+ dfs_util(ix,jy-1,m,n,grid)+ dfs_util(ix,jy+1,m,n,grid);
    }
    return 0 ;
}


int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    int max_ans = 0 ;
    for (int i1 = 0; i1 < m; i1++)
        for (int j1 = 0; j1 < n; j1++)
            if(grid[i1][j1]==1 )
                max_ans = max(max_ans , dfs_util(i1,j1,m,n,grid));


    return max_ans ;   
}





int main(int argc, char const *argv[])
{

    vector<vector<int>> arr1 = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout<<endl<<maxAreaOfIsland(arr1);

    return 0;
}



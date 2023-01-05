// https://leetcode.com/problems/sort-the-matrix-diagonally/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int arrx[] = {-1,0,1,0};
int arry[] = {0,1,0,-1};

bool okposition(int i1,int j1 , int n , int m)
{
    return (i1<n &&i1>=0 && j1>=0 && j1<m);
}


void dfs_util(int i1 , int j1 , int n , int m , vector<vector<char>>& grid) 
{
    grid[i1][j1]='0';
    for (int i = 0; i < 4; i++)
        if(okposition(i1+arrx[i] , j1+arry[i] , n ,m) && grid[i1+arrx[i]][j1+arry[i]] =='1')
            dfs_util(i1+arrx[i] , j1+arry[i] , n,m ,grid);
        
}

int numIslands(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int ans1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(grid[i1][j1]=='1')
                dfs_util(i1, j1 ,n,m, grid) ,ans1++ ;
            //dfs_util 

    return ans1 ;    

}

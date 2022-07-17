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


int bfs_util(int ix , int jy ,int m ,int n , vector<vector<int>>&grid)
{
    queue<pair<int,int>> q1 ;
    if(grid[ix][jy]==1)
        q1.push({ix,jy});

    int ans1 = 0;
    while(!q1.empty())
    {
        int firsx = q1.front().first ; 
        int secony = q1.front().second ; 
        q1.pop();
        if(grid[firsx][secony]==0)
            continue ; 
        ans1++ ;
        grid[firsx][secony] = 0 ;
        if(firsx-1>=0 && secony>=0 && firsx-1<m&& secony<n && grid[firsx-1][secony]==1)
            q1.push({firsx-1,secony});
        
        if(firsx+1>=0 && secony>=0 && firsx+1<m&& secony<n && grid[firsx+1][secony]==1)
            q1.push({firsx+1,secony});
        
        if(firsx>=0 && secony-1>=0 && firsx<m&& secony-1<n && grid[firsx][secony-1]==1)
            q1.push({firsx,secony-1});
        
        if(firsx>=0 && secony+1>=0 && firsx<m&& secony+1<n && grid[firsx][secony+1]==1)
            q1.push({firsx,secony+1});

    }
    return ans1 ;
}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    int max_ans = 0 ;
    for (int i1 = 0; i1 < m; i1++)
        for (int j1 = 0; j1 < n; j1++)
            if(grid[i1][j1]==1 )
                max_ans = max(max_ans , bfs_util(i1,j1,m,n,grid));


    return max_ans ;   
}

int main(int argc, char const *argv[])
{

    // vector<vector<int>> arr1 = {
    //     {0,0,1,0,0,0,0,1,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //     {0,1,1,0,1,0,0,0,0,0,0,0,0},
    //     {0,1,0,0,1,1,0,0,1,0,1,0,0},
    //     {0,1,0,0,1,1,0,0,1,1,1,0,0},
    //     {0,0,0,0,0,0,0,0,0,0,1,0,0},
    //     {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //     {0,0,0,0,0,0,0,1,1,0,0,0,0}
    // };

        vector<vector<int>> arr1 = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };
    cout<<endl<<maxAreaOfIsland(arr1);

    return 0;
}

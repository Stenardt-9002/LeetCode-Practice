// https://leetcode.com/problems/count-sub-islands/?envType=study-plan&id=graph-i







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

// void dfs_util(int srcx , int srcy , int n , int m  ,vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int &current_ans) 
// {
//     if(srcx<0||srcy<0||srcx>=n||srcy>=m || grid2[srcx][srcy]==0)
//         return ;
    
//     if(grid1[srcx][srcy]==0)
//         current_ans =0 ;
//     grid2[srcx][srcy] = 0;
//     dfs_util(srcx+1 , srcy , n , m , grid1 , grid2 , current_ans);
//     dfs_util(srcx , srcy+1 , n , m , grid1 , grid2 , current_ans);
//     dfs_util(srcx-1 , srcy , n , m , grid1 , grid2 , current_ans);
//     dfs_util(srcx , srcy-1 , n , m , grid1 , grid2 , current_ans);

// }

// class Solution 
// {
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
//     {
//             int n = grid1.size()    ;
//         int m = grid1[0].size()    ;

//         int ans = 0 ,allowed_subset = 1;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//             {
//                 allowed_subset = 1;
//                 if(grid2[i][j])
//                 {
//                     dfs_util(i , j , n , m , grid1 , grid2 , allowed_subset);
//                     if(allowed_subset)
//                         ans++ ;
//                 }
//             }
//         return ans ;     
//     }
// };

























//bfs solution
static int arr[] = {0,-1,0,1,0};
int bfs_util(int srcx , int srcy , int n , int m  ,vector<vector<int>>& grid1, vector<vector<int>>& grid2 ) 
{
    int current_ans = 1 ;
    queue<pair<int , int >> q1 ; 
    q1.push({srcx , srcy});
    grid2[srcx][srcy]= 0 ;
    while (!q1.empty())
    {
        int curx = q1.front().first ;
        int cury = q1.front().second ;
        if(grid1[curx][cury]==0)
            current_ans = 0 ;
        q1.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = curx+arr[i];
            int newy = cury+arr[i+1];
            if(newx<0 || newy <0 || newx>=n || newy>=m || grid2[newx][newy]==0)
                continue ;
            grid2[newx][newy]=0;
            q1.push({newx , newy});
        }
        
    }
    
    return current_ans ;

}

class Solution 
{
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int n = grid1.size(), m = grid1[0].size()    ;

        int ans = 0 ;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(grid2[i][j] && bfs_util(i,j,n,m,grid1 , grid2))
                    ans++ ;
        return ans ;      
    }
};
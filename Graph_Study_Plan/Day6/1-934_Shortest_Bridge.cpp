// https://leetcode.com/problems/shortest-path-in-binary-matrix/?envType=study-plan&id=graph-i








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







static int arrx[] = {-1,-1,-1,0,0,1,1,1};
static int arry[] = {-1,0,1,-1,1,-1,0,1};






// static int direx[] = {0,-1,0,1,0};
// class Solution {
// public:
//     int shortestBridge(vector<vector<int>>& grid) 
//     {
//         int n = grid.size();
//         int sum1 = 0;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 sum1+=grid[i][j];

//         if(sum1==(n*n))
//             return 0 ;
//         if(sum1==0)
//             return -1 ; 
        
//         queue<pair<int,int>> q1 ;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 if(grid[i][j])
//                 {
//                     q1.push({i,j});
//                     grid[i][j] = -1 ;
//                 }
        
//         sum1 = 0 ;
//         while(!q1.empty())
//         {
            
//             sum1++ ;
//             int size = q1.size();
//             while(size--)
//             {
//                 pair<int,int> p1 = q1.front();
//                 q1.pop();
//                 for (int d = 0; d < 4; d++)
//                 {
//                     int newx = p1.first + direx[d];
//                     int newy = p1.second+ direx[d+1];
//                     if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]!=-1 && grid[newx][newy]!=-2)
//                     {
//                         if(grid[newx][newy]==-1 )
//                             return sum1 ;
//                         q1.push({newx,newy});
//                         grid[newx][newy] = -2 ;
//                     }
//                 }
//             }
//         }

//         return sum1 ;
//     }
// };












static int direx[] = {0,-1,0,1,0};
class Solution {
public:
    void dfs_util(vector<vector<int>>&grid , int srcx , int srcy , queue<pair<int,int>>&q1)
    {
        if(min(srcx , srcy)>=0 && max(srcx , srcy)<grid.size() && grid[srcx][srcy]==1)
        {
            grid[srcx][srcy]=2;
            q1.push({srcx,srcy});
            for (int d = 0; d < 4; d++)
                dfs_util(grid , srcx+direx[d] , srcy+direx[d+1] , q1);
        }
        return ;
    }


    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int sum1 = 0;
        queue<pair<int,int>> q1 ;
        for (int i = 0; q1.empty()&&i < n; i++)
            for (int j = 0;q1.empty()&& j < n; j++)
                dfs_util(grid , i , j , q1);

        while (!q1.empty())
        {
            int size = q1.size();
            while (size--)
            {
                pair<int,int> p = q1.front();
                q1.pop();
                for (int d = 0; d < 4; d++)
                {
                    int newx = p.first+direx[d];
                    int newy = p.second+direx[d+1];
                    if(min(newx , newy)>=0 && max(newx,newy)<n)
                    {
                        if(grid[newx][newy]==1)
                            return grid[p.first][p.second]-2 ;

                        if(grid[newx][newy]==0)
                        {
                            grid[newx][newy] = grid[p.first][p.second]+1 ;
                            q1.push({newx,newy});
                        }
                    }
                }
            }
        }
        return 0;
    }
};


















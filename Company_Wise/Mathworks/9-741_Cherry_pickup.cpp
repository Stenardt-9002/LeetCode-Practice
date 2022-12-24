// https://leetcode.com/problems/cherry-pickup/







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





// void dfs_solution_end_to_start(int row , int col , int n , vector<vector<int>>&grid , int curre_cherries , int &final_ans)
// {
//     if(row<0||row>=n || col<0||col>=n||grid[row][col]==-1)
//         return ; 

//     if(row==0 && col==0)
//     {
//         final_ans = max(final_ans , curre_cherries);
//         return ; 
//     }
        
//     int cur = grid[row][col];
//     grid[row][col] = 0 ;//now disappeared 
//     dfs_solution_end_to_start(row,col-1 , n , grid , curre_cherries+cur ,final_ans);
//     dfs_solution_end_to_start(row-1,col , n , grid , curre_cherries+cur ,final_ans);
//     grid[row][col] = cur ;//now appeared 
// }



// void dfs_solution_start_to_end(int row , int col , int n , vector<vector<int>>&grid , int curre_cherries , int &final_ans)
// {
//     if(row<0||row>=n || col<0||col>=n||grid[row][col]==-1)
//         return ; 

//     if(row==n-1 && col==n-1)
//         dfs_solution_end_to_start(row , col , n , grid , curre_cherries , final_ans);
//     int cur = grid[row][col];
//     grid[row][col] = 0 ;//now disappeared 
//     dfs_solution_start_to_end(row,col+1 , n , grid , curre_cherries+cur ,final_ans);
//     dfs_solution_start_to_end(row+1,col , n , grid , curre_cherries+cur ,final_ans);
//     grid[row][col] = cur ;//now appeared 

// }




// class Solution 
// {
// public:
//     int cherryPickup(vector<vector<int>>& grid) 
//     {
//         int n = grid.size();
//         if(n==1)
//             return grid[0][0];
//         int curent = 0 ;
//         int final_ans = 0 ;
//         dfs_solution_start_to_end(0 , 0 , n , grid ,curent ,final_ans);
//         return final_ans ;    
//     }
// };





















































int dp_solution_start_to_end(int r1 , int c1 , int r2 , int n , vector<vector<int>>& grid , vector<vector<vector<int>>>&dp1)
{
    int c2 = r1+c1-r2 ;
    if(r1<0||r2<0||r1>=n||r2>=n||c1<0||c2<0||c1>=n||c2>=n|| grid[r1][c1]==-1 ||grid[r2][c2]==-1)
        return INT_MIN ;

    
    if(r1==n-1 && c1 ==n-1)
        return grid[r1][c1] ;

    if(dp1[r1][c1][r2]!=-1)
        return dp1[r1][c1][r2] ;

    int cherry = 0 ;
    if(r1==r2 && c1==c2)
        cherry = grid[r1][r2];
    else 
        cherry = grid[r1][r2]+grid[r2][c2];

    int f1 = dp_solution_start_to_end(r1+1 , c1 , r2   , n,grid , dp1);
    int f2 = dp_solution_start_to_end(r1+1 , c1 , r2+1 , n,grid , dp1);
    int f3 = dp_solution_start_to_end(r1 , c1+1 , r2  , n,grid , dp1);
    int f4 = dp_solution_start_to_end(r1 , c1+1 , r2+1 , n,grid , dp1);

    cherry+=max({f1,f2,f3,f4});
    dp1[r1][c1][r2] = cherry;
    return cherry ;

}








class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(n==1)
            return grid[0][0];

        vector<vector<vector<int>>>dp1(n,vector<vector<int>>(n,vector<int>(n,-1)));
        
        int final_ans = dp_solution_start_to_end(0 , 0 ,0, n , grid ,dp1);
        return final_ans ;    
    }
};

























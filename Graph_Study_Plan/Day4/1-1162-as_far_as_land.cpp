// https://leetcode.com/problems/as-far-from-land-as-possible/





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






// static int arr[] = {0,-1,0,1,0};

// int min_bfs_distance(int i , int j , int n , vector<vector<int>> &grid)
// {
//     vector<vector<bool>>visisted(n,vector<bool>(n,false));
//     queue<vector<int>>q1 ; //srcx , srcy , cur_dis 
//     q1.push({i,j,0});
//     visisted[i][j] = true ;
    
//     while (!q1.empty())
//     {
//         int srcx  =  q1.front()[0];
//         int srcy  =  q1.front()[1];
//         int curdis = q1.front()[2];
//         if(grid[srcx][srcy]==1)    
//             return curdis ;
        
//         // visisted[srcx][srcy] = true ;
//         q1.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int newx = srcx+arr[i];
//             int newy = srcy+arr[i+1];
            
//             if(newx>=0 && newx<n && newy>=0 && newy<n && !visisted[newx][newy])
//             {
//                 visisted[newx][newy] = true ;
//                 q1.push({newx , newy , curdis+1});
//             }
//         }
//     }
//     return -1  ;    

// }




// class Solution 
// {
// public:
//     int maxDistance(vector<vector<int>>& grid) 
//     {
//         bool zero_found = false ;
//         bool one_found = false ;
//         int n = grid.size();
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 if(grid[i][j])
//                     one_found = true ;
//                 else 
//                     zero_found = true ;


//         if(!(one_found && zero_found))
//             return -1 ;



//         int max_min_distance = -2 ;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 if(grid[i][j]==0)
//                     max_min_distance = max(max_min_distance , min_bfs_distance(i,j,n,grid));


//         return max_min_distance ;    
//     }
// };























































































































static int arr[] = {0,-1,0,1,0};

int min_bfs_distance(int i , int j , int n , vector<vector<int>> &grid)
{
    vector<vector<bool>>visisted(n,vector<bool>(n,false));
    queue<vector<int>>q1 ; //srcx , srcy , cur_dis 
    q1.push({i,j,0});
    visisted[i][j] = true ;
    
    while (!q1.empty())
    {
        int srcx  =  q1.front()[0];
        int srcy  =  q1.front()[1];
        int curdis = q1.front()[2];
        if(grid[srcx][srcy]==1)    
            return curdis ;
        
        // visisted[srcx][srcy] = true ;
        q1.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = srcx+arr[i];
            int newy = srcy+arr[i+1];
            
            if(newx>=0 && newx<n && newy>=0 && newy<n && !visisted[newx][newy])
            {
                visisted[newx][newy] = true ;
                q1.push({newx , newy , curdis+1});
            }
        }
    }
    return -1  ;    

}



static short arr[] = {0,-1,0,1,0};
class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        bool zero_found = false ;
        bool one_found = false ;
        int n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(grid[i][j])
                    one_found = true ;
                else 
                    zero_found = true ;


        if(!(one_found && zero_found))
            return -1 ;



        //bfs approach 
        queue<pair<short,short>> q1 ;
        for (short i = 0; i < n; i++)
            for (short j = 0; j < n; j++)
                if(grid[i][j]==1)
                    q1.push({i,j});

        short cur_dis = 0;
        while (!q1.empty())
        {
            cur_dis++ ;
            short n1 = q1.size();
            while (n1--)
            {
                short curx = q1.front().first ;
                short cury = q1.front().second ;
                q1.pop();
                for (short i = 0; i < 4; i++)
                {
                    short newx = curx+arr[i];
                    short newy = cury+arr[1+i];
                    if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==0)
                    {
                        grid[newx][newy] = cur_dis ;
                        q1.push({newx,newy});
                    }
                }
                
            }
            
        }
        

        return cur_dis-1 ;    
    }
};










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

// void get_graph(vector<vector<int>>& grid , vector<int>*graph ,map<pair<int,int>,int>index_to_nodes,map<int,pair<int,int>>nodes_to_index )
// {
//         int n = grid.size()    ;
//         int m = grid[0].size();
//         int dirc[] = {0,-1,0,1,0};
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//                 if(grid[i][j])
//                 {
//                     int cur_g = index_to_nodes[{i,j}];
//                     for (int d = 0; d < 4; d++)
//                     {
//                         int newx = i+dirc[d];
//                         int newy = j+dirc[d+1];
//                         if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1)
//                             graph[cur_g].push_back(index_to_nodes[{newx,newy}]);
//                     }
//                 }
        
// }
// bool bfs_al(vector<vector<int>> grid) 
// {
//     int n = grid.size()    ;
//     int m = grid[0].size();
//     queue<pair<int,int>>q1 ;
//     q1.push({0,0});
//     if(!(grid[0][0]&& grid[n-1][m-1]))
//         return false ;
//     grid[0][0] = 0 ;
//     while (!q1.empty())
//     {
//         int frontx = q1.front().first;
//         int fronty = q1.front().second;
//         q1.pop();
//         int newx = frontx+1 ; 
//         int newy = fronty+1 ;
//         //right side
//         if( newy<m && grid[frontx][newy]==1)
//         {
//             if(frontx == n-1 && newy ==m-1)
//                 return true ;
//             grid[frontx][newy] = 0;
//             q1.push({frontx , newy});
//         }
//         if( newx<n && grid[newx][fronty]==1)
//         {
//             if(newx == n-1 && fronty == m-1)
//                 return true ;
//             grid[newx][fronty] = 0;
//             q1.push({newx , fronty});
//         }
        
//     }
//     return false ;
        
// }

// class Solution {
// public:
//     bool isPossibleToCutPath(vector<vector<int>>& grid) 
//     {
//         int n = grid.size()    ;
//         int m = grid[0].size();

//         //do bfs 
//         if(!bfs_al(grid))
//             return true ;



//         map<pair<int,int>,int>index_to_nodes ; 
//         map<int,pair<int,int>>nodes_to_index ; 
//         int cnt = 0 ;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//                 if(grid[i][j]==1)
//                 {
//                     index_to_nodes[{i,j}] = cnt ;
//                     nodes_to_index[cnt++] = {i,j};
//                 }

        

//         vector<int>*graph ; 
//         graph = new vector<int>[cnt];
//         get_graph(grid , graph , index_to_nodes , nodes_to_index);


//         vector<bool> visited(cnt,false);
//         vector<bool> articulation_pt(cnt,false);
//         vector<int>discovery_time(cnt, 0 );
//         vector<int>low_pt(cnt, 0 );





//         delete [] graph ;
//     }
// };



// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) 
//     {
//         set<int> se_hash ;
//         for(auto ele:banned)    
//             se_hash.insert(ele);
//         int ans = 0 ;
//         for (int i1 = 1; i1 <=n && maxSum>0; i1++)
//             if(se_hash.find(i1)==se_hash.end() &&maxSum>=i1)
//             {
//                 maxSum-=i1 ;
//                 ans++;
//             }
//             else if(maxSum<i1)
//                 maxSum = -1 ;
        
//         return ans ;
        
//     }
// };









































    bool dfs_u(vector<vector<int>>&grapg , int i ,int j, int n , int m)
    {
        if(i==n-1&&j==m-1)
            return true ;
        if(i>=n||j>=m || grapg[i][j]==0)
            return false ;

        grapg[i][j] = 0 ;
        return dfs_u(grapg , i , j+1 , n,m)||dfs_u(grapg , i+1 , j , n,m);
    }



class Solution 
{
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size()    ;
        int m = grid[0].size();
        //do two dfs 
        if(!dfs_u(grid ,0 ,0 ,n ,m))
            return true ;
        grid[0][0] = 1;
        return !dfs_u(grid ,0,0,n,m);
    }
};






















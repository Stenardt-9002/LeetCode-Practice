// https://leetcode.com/problems/sum-of-distances-in-tree/description/







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









// class Solution {
// public:
//     void dfs_child(int src , int parent , vector<vector<int>>graph , vector<int>&child_count , vector<int>&ans1)
//     {
//         for(auto child : graph[src])
//         {
//             if(child==parent)
//                 continue;
//             dfs_child(child,src,graph,child_count ,ans1);
//             child_count[src]+=child_count[child];
//             ans1[src]+=(ans1[child]+child_count[child]);
//         }
//     }

//     void dfs2_child(int src , int parent , vector<vector<int>>&graph , vector<int>&child_count , vector<int>&ans1,int n )
//     {
//         for(auto child : graph[src])
//         {
//             if(child==parent)
//                 continue ;
//             ans1[child] = (ans1[src]-child_count[child]+n-child_count[child] );
//             dfs2_child(child,src,graph,child_count ,ans1,n);
//         }
//     }
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
//     {
//         vector<vector<int>>graph1(n);
//         for(auto edge : edges)
//         {
//             graph1[edge[0]].push_back(edge[1]);
//             graph1[edge[1]].push_back(edge[0]);
//         }
//         vector<int>child_co(n,1)    ;
//         vector<int>ans1(n,0)    ;

//         dfs_child(0,-1,graph1,child_co , ans1);
//         dfs2_child(0,-1,graph1,child_co , ans1,n);
//         return ans1 ;
//     }
// };



































class Solution {
public:
    vector<vector<int>>graph;
    vector<int> child_count ,ans1 ;
    void dfs_child(int src , int parent=-1)
    {
        for(auto child : graph[src])
        {
            if(child==parent)
                continue;
            dfs_child(child,src) ;
            child_count[src]+=child_count[child];
            ans1[src]+=(ans1[child]+child_count[child]);
        }
    }

    void dfs2_child(int src , int n ,int parent =-1)
    {
        for(auto child : graph[src])
        {
            if(child==parent)
                continue ;
            ans1[child] = (ans1[src]-child_count[child]+n-child_count[child] );
            dfs2_child(child,n,src);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        graph.resize(n);
        child_count.resize(n,1);
        ans1.resize(n,0);
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs_child(0);
        dfs2_child(0,n,-1);
        return ans1 ;
    }
};







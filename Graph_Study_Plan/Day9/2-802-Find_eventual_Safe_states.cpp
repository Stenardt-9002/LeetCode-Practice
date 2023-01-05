
// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=study-plan&id=graph-i




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



// class Solution {
// public:
//     bool dfs_util(int src , vector<int>&visited , vector<vector<int>>graph)
//     {
//         visited[src] = 1;
//         for(auto child : graph[src])
//         {
//             if((visited[child]==1 )||(visited[child]==0 && !dfs_util(child , visited , graph)))
//                 return false ;
//         }
//         visited[src] = 2;
//         return true ;//no cycle 
//     }


//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
//     {
//         int n = graph.size();
//         vector<int>visited(n,0)    ,ans1 ;

//         for (int i = 0; i < n; i++)
//             if(visited[i]==2 || dfs_util(i , visited , graph))
//                 ans1.push_back(i);
        

//         return ans1 ;
//     }
// };








class Solution {
public:
    bool dfs_util(int src , vector<bool>&visited , vector<bool>&safe_nodes , vector<bool>&cycle_nodes , vector<vector<int>>graph)
    {
        if(cycle_nodes[src])
            return false ;//cycle find 
        if(safe_nodes[src])
            return true ;// not cycle 

        if(visited[src])
        {
            cycle_nodes[src] = true ;
            return false ;//cycle 
        }
        visited[src] = true ;
        for(auto child : graph[src])
            if(!dfs_util(child , visited , safe_nodes , cycle_nodes , graph))
            {
                cycle_nodes[child] = true ;
                return false ;//in cycle
            }

        safe_nodes[src] = 1;
        return true ;//no cycle 
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<bool>visited(n,0)  , safe_nodes(n,0) , cycle_nodes(n,0);
        vector<int> ans1 ;

        for (int i = 0; i < n; i++)
            if(dfs_util(i , visited ,safe_nodes , cycle_nodes , graph))
                ans1.push_back(i);
        

        return ans1 ;
    }
};









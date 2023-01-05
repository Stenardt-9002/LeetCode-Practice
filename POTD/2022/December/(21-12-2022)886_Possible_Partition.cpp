// https://leetcode.com/problems/possible-bipartition/







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




bool bfs_traversal(int src , vector<int>&visited , vector<vector<int>>graph)
{
    queue<int> q1 ;
    q1.push(src);
    visited[src] = 0 ;
    while (!q1.empty())
    {
        src = q1.front();
        q1.pop();
        for(auto child : graph[src])
        {
            if(visited[child]==-1)
            {
                q1.push(child);
                visited[child] = 1-visited[src];
            }
            else if(visited[child] == visited[src])
                return true ;//same colour
        }
    }
    return false ;
}

bool dfs_traversal(int src ,int colr ,  vector<int>&visited , vector<vector<int>>graph)
{
    visited[src] = colr ;
    for(auto child : graph[src])
        if(visited[child]==-1 && dfs_traversal(child , 1-colr , visited , graph))
            return true ;//same colour
        else if(visited[child] == visited[src])
            return true ;//same colour

    return false ;
}




class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<int>visited(n,-1)    ;
        vector<vector<int>>graph(n);
        for(auto con:dislikes)
        {
            int first = con[0];
            int second = con[1];
            graph[first-1].push_back(second-1);
            graph[second-1].push_back(first-1);
        }

        for(int i = 0 ;i<n;++i)
            if(visited[i]==-1 && bfs_traversal(i , visited , graph))
                return false ;
        // for(int i = 0 ;i<n;++i)
        //     if(visited[i]==-1 && dfs_traversal(i,0 , visited , graph))
        //         return false ;
        return true ;
    }
};










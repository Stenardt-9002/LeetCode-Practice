
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;





    bool dfs_util(int src, vector<int> &visited, vector<int> &safe_n, vector<int> &cycle, vector<vector<int>> &graph)
    {
        if(cycle[src]==1)
            return false ;
        if(safe_n[src]==1)
            return true ;
        if(visited[src]==1)
        {
            //already in cycle
            cycle[src]=1 ;
            return false ;
        }
        visited[src] = 1;
        //all neighbours
        for(auto child : graph[src])
            if(!dfs_util(child,visited,safe_n,cycle,graph)) {
                cycle[child] = 1;
                return false;
            }
        safe_n[src] = 1;
        return true ;
    }

    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>safe_n(n,0);
        vector<int>cycle(n,0);

        vector<int>ans1;
        for (int i = 0; i < n; ++i)
            if(dfs_util(i,visited,safe_n,cycle,graph))
                ans1.push_back(i);

        return ans1;
    }
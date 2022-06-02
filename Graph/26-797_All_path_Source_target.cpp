
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;








    void dfs_util(int src, int target, vector<int> current, vector<vector<int>> &ans1, vector<vector<int>> &graph1)
    {
        if(src==target)
        {
            current.push_back(src);
            ans1.push_back(current);
            return ;
        }
        current.push_back(src);
        for(auto child : graph1[src])
        {
            dfs_util(child,target,current,ans1,graph1);
        }
        current.pop_back();
        return ;
    }

    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> current;
        vector<vector<int>> ans1 ;
        int src = 0;
        int target = graph.size()-1;
        dfs_util(src, target, current, ans1, graph);
        return ans1 ;
    }
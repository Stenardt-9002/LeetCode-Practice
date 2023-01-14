// https://leetcode.com/problems/same-tree/description/









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












class Solution {
public:


    int dfs_util(int src , int distance , int parent , vector<bool>hasApple , vector<int>*graph)
    {
        int ans = 0 , curdis ;
        for(auto &child:graph[src])
            if(child!=parent)
            {
                curdis = dfs_util(child ,distance+1 , src ,hasApple , graph);
                if(curdis>0)
                    ans+=(curdis-distance);
            }
        if(hasApple[src]||ans>0)
            return ans+distance ;
        return 0;
    }


    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<int>* graph1 = new vector<int>[n];
        int ans = 0;
        for(auto vec:edges)
        {
            graph1[vec[0]].push_back(vec[1]);
            graph1[vec[1]].push_back(vec[0]);
        }

        return dfs_util(0,0,-1,hasApple , graph1);

    }
};



















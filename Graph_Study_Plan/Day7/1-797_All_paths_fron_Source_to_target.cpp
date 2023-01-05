
// https://leetcode.com/problems/all-paths-from-source-to-target/?envType=study-plan&id=graph-i








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






class Solution {
public:
    void dfs(vector<vector<int>>& graph , int node , vector<int>&cur_path , vector<vector<int>>&ans)
    {
        cur_path.push_back(node);
        if(node==graph.size()-1)
            ans.push_back(cur_path);
        else
        for(auto child : graph[node]) 
            dfs(graph , child , cur_path , ans);
        cur_path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans ;
        vector<int>cur_path ;
        dfs(graph , 0 , cur_path , ans);

        return ans ;    
    }
};
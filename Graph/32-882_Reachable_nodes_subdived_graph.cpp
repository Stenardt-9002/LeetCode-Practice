

// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int dfs_u(int src,int cur_cunt ,vector<bool>&visisted ,vector<vector<int>> *graph1)
{
    int sum_val = 1;
    for(auto &nodes:graph1[src])
    {
        int weight = nodes[1];
        int second_s = nodes[0];
        if(nodes[1]>cur_cunt)
        {
            //remove edge both side
            std::vector<vector<int>> ::iterator it ;
            it = std::find(graph1[src].begin(),graph1[src].end(),nodes);
            
        }
    }   
}



int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
{
    vector<vector<int>> *graph1 = new vector<vector<int>>[n]   ;
    for (auto x: edges)
        graph1[x[0]].push_back({x[1],x[2]}) ,graph1[x[1]].push_back({x[0],x[2]})    ;

    vector<bool>visisted(n,false);
    int coubht = dfs_u(0,maxMoves,visisted,graph1);
    return coubht ;

}









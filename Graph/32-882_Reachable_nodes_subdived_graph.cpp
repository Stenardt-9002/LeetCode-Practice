

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
    int ans1 = 0,mpoves ,nde;
    unordered_map<int,unordered_map<int,int>>edge_list_that_saves_weight ;
    for (auto e:edges)
        edge_list_that_saves_weight[e[1]][e[0]] = edge_list_that_saves_weight[e[0]][e[1]] = e[2];

    priority_queue<pair<int,int>>pq_var ; //moves,nodes //sort by nodes
    pq_var.push({maxMoves,0});

    unordered_map<int,int>visited ;

    while (pq_var.size())
    {
        mpoves = get<0>(pq_var.top()) ; 
        nde = get<1>(pq_var.top()) ; 

        // int nde = pq_var.top().second ; 
        pq_var.pop();

        if(visited.find(nde)==visited.end())
        {
            visited[nde] = mpoves ;
            for(auto neig:edge_list_that_saves_weight[nde])
            {
                int newmpoves = mpoves-neig.second-1 ;//inlcuding node //neig is node, weight
                if(visited.find(neig.first)==visited.end() && newmpoves>=0)
                    pq_var.push({newmpoves, neig.first });
            }
        }
    }

    ans1 = visited.size();//theses nodes were reached .
    for(auto ed : edges)
    {
        int firside = 0,secondside = 0;
        if(visited.find(ed[0])!=visited.end())
            firside = visited[ed[0]];//moves
        if(visited.find(ed[1])!=visited.end())
            secondside = visited[ed[1]];//moves
        
        ans1+=min(firside+secondside,ed[2]);//if the weight cover the edge from both side 
    }


    return ans1;


}









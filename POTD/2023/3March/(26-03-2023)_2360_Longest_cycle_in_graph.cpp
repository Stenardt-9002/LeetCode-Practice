// https://leetcode.com/problems/longest-cycle-in-a-graph/


















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

    void dfs_u(int src , vector<int>&edges , unordered_map<int,int> &dist , vector<bool>&vis , int &ans)
    {
        vis[src] = true ; 
        int child = edges[src] ; 
        if(child!=-1)
        {
            if(!vis[child])
            {
                dist[child] = dist[src]+1 ; 
                dfs_u(child , edges , dist , vis , ans) ;
            }
            else if (dist.count(child))
                ans = max(ans , dist[src]-dist[child]+1);
        }
    }


    int longestCycle(vector<int>& edges) 
    {
        int ans = -1 ;
        int n = edges.size();
        vector<bool> visited(n,false);
        for(int i = 0 ; i<n;i++)
            if(!visited[i])
            {
                unordered_map<int,int> dist ;
                dist[i] = 1 ; 
                dfs_u(i , edges , dist , visited,ans);
            }


        return ans ; 
    }
};









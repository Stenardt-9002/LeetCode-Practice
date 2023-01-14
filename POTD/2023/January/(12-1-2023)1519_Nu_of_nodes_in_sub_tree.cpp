// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/




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

    void dfs_util(int src , int parent , vector<int>*graph , vector<int>&ans,vector<int>&hash_char,string labels)
    {
        if(ans[src]==0)
        {
            ans[src] = 1 ;
            for(auto child : graph[src])
            if(child!=parent)
            {
                vector<int> hash_char2(26,0);
                dfs_util(child , src , graph , ans, hash_char2,labels);
                for(int k = 0; k<26;++k)
                    hash_char[k]+=hash_char2[k];
            }
            ans[src] = ++hash_char[labels[src]-'a'];
        }
    }




    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int>*graph = new vector<int>[n];
        for(auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> ans(n,0);
        vector<int>hash_char(26,0);
        dfs_util(0,-1,graph ,ans,hash_char,labels);
        return ans ;
    }
};
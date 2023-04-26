// https://leetcode.com/problems/number-of-good-paths/










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




class Union_Find
{
    
public:
    vector<int> parent , rank ;
    int cnt  ; 



    Union_Find(int cnt):cnt(cnt) 
    {
        parent = vector<int>(cnt);
        rank =  vector<int>(cnt,0);
        for(int i = 0 ; i<cnt ; i++)    parent[i] = i ; 
    }
    int find(int p)
    {
        if(p==parent[p])
            return p ;
        return parent[p] = find(parent[p]);
    }
    bool same_parent(int p , int q)
    {
        return find(p) == find(q);
    }
    void connect(int p , int q)
    {
        int pi = find(p);
        int qi = find(q);
        if(pi==qi)
            return ; 
        if(rank[pi]<rank[qi])
            parent[pi] = qi ; 
        else 
        {
            parent[qi] = pi ; 
            if(rank[pi]==rank[qi])
                rank[qi]++;
        }
        --cnt;
    }

};








class Solution {
public:


    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n = vals.size()    ;
        int edges_size = edges.size();
        int ans = 0 ;
        vector<vector<int>>newgraph(n) ; //only for those nodes that have value less than it
        map<int,vector<int>>values_to_nodes ;
        for(int i = 0 ; i<n;i++)    values_to_nodes[vals[i]].push_back(i);
        for(auto&e:edges)
        {
            int u = e[0],v = e[1];
            if(vals[u]>=vals[v])
                newgraph[u].push_back(v);
            else if(vals[u]<=vals[v])
                newgraph[v].push_back(u);
        }

        Union_Find dsu(n);
        for(auto [value , nodes_n]: values_to_nodes)
        {
            for(int start: nodes_n)
                for(int end : newgraph[start])
                    dsu.connect(start,end);
            
            unordered_map<int,int>countp ;
            for(int start : nodes_n )
                countp[dsu.find(start)]++ ;
            
            for(auto it : countp)
                ans+=(it.second *(it.second-1)/2);
        }


        ans+=n ;
        return ans ;

    }
};










// class Solution {
// public:

//     int find_DSU(vector<int>&par , int i)
//     {
//         if(i==par[i])
//             return i ;
//         return par[i] = find_DSU(par , par[i]);
//     }
//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
//     {
//         int n = vals.size()    ;
//         int edges_size = edges.size();
//         int ans = 0 ;
//         vector<vector<int>>graph1(n);
//         vector<int>parent(n);
//         for(int i=0;i<n;i++)
//             graph1[i] = {vals[i] , 1} , parent[i] = i ;
//         sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
// 	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
// 		});
//         for(int i=0;i<edges_size;i++)
//         {
//             int fir = find_DSU(parent , edges[i][0]);
//             int sec = find_DSU(parent , edges[i][1]);
//             if(graph1[fir][0]!=graph1[sec][0])
//             {
//                 if(graph1[fir][0]>graph1[sec][0])
//                     parent[sec] = fir ;
//                 else 
//                     parent[fir] = sec ;
//             }
//             else 
//             {
//                 parent[fir] = sec ;
//                 ans = ans+(graph1[fir][1]*graph1[sec][1]);
//                 graph1[sec][1]= graph1[sec][1]+graph1[fir][1];
//             }
//         }
//         ans+=n ;
//         return ans ;

//     }
// };
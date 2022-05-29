// https://leetcode.com/problems/redundant-connection/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int find1(int x , vector<int>&parent )
{
    if(x==parent[x])
        return x ; 
    return parent[x] = find1(parent[x],parent);
}

bool Union_util(int u,int v , vector<int> &parent ,vector<int>&size)
{
    int pu = find1(u,parent);
    int pv = find1(v,parent);
    if(pu==pv)
        return false ;
    if(size[pu]>size[pv])
    {
        size[pu]+=size[pv];
        parent[pv] = pu ;
    }
    else
    {
        size[pv]+=size[pu];
        parent[pu] = pv ;
    }
    return true ;
}



vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
    int n = edges.size();
    vector<int>parent(n,0);
    for(int i1=0;i1<n;i1++)
        parent[i1] = i1 ;
    vector<int>size(n,1);
    for(auto e : edges)
        if(!Union_util( e[0]-1, e[1]-1 , parent ,size))
            return {e[0],e[1]};

    return {};
}






// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
















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











int dfs_util(int src , vector<vector<int>> graph , vector<bool>&visited)
{
    visited[src] = true ;
    int current_nodes = 1 ;
    for(auto child:graph[src])
        if(!visited[child])
            current_nodes+=dfs_util(src , graph , visited);
    return current_nodes ;
}   

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        
        vector<int>groups;
        vector<vector<int>>graph(n);
        vector<bool>visited(n,false);
        for(auto ed: edges)
        {
            graph[ed[0]].push_back(ed[1]);
            graph[ed[1]].push_back(ed[0]);
        }

        for (int ans = 0; ans < n; ans++)
            groups.push_back(dfs_util(ans , graph , visited));

        
        long long int sum = 0 ,ans = 0; 
        for(auto v: groups)
            sum+=v ;
        
        for(auto e : groups)
        {
            long long int temp = e*(sum-e);
            ans+=temp ;
            sum = sum-e;
        }




        return ans ;
    }
};




class Solution {
public:

    vector<long long int> parent , size ;

    long long int find_dsu(long long int a )
    {
        if(parent[a]==a)
            return a ;
        return parent[a] = find_dsu(parent[a] );
    }
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        long long int N = n;
        long long int ans = N*(N-1)/2 ;
        parent.resize(n);
        size.resize(n);
        for(int i = 0 ; i<n;i++)
        {
            parent[i] = i ;
            size[i] = 1;
        }
        for(auto ed : edges)
        {
            int ro = find_dsu(ed[0]);
            int r1 = find_dsu(ed[1]);
            if(ro==r1)
                continue ;
            parent[ro] = r1 ;
            size[r1]+=size[ro];
        }
        for(int i = 0 ; i<n;i++)
            if(parent[i]==i)
                ans-=((size[i] *(size[i]-1))/2 );



        return ans ;
    }






};










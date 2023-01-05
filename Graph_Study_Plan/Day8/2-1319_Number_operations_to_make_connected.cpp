





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
    void dfs_util(int src ,int n,vector<vector<int>>graph1 , vector<bool>&visited )
    {
        visited[src] = false ;
        for(auto child : graph1[src])
            if( visited[child] ) 
                dfs_util(child ,n , graph1 , visited );

        return ;
    }
    void bfs_util(int src ,vector<vector<int>>graph1 , vector<bool>&visited )
    {
        queue<int> q1 ; 
        visited[src] = false ;
        q1.push(src) ;
        while (!q1.empty())
        {
            int top  = q1.front() ;
            q1.pop(); 
            for(auto neig : graph1[top])
                if(visited[neig])
                {
                    q1.push(neig);
                    visited[neig] = false ;
                }
        }
        

    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        vector<bool> visited(n,true);
        if(n-1>connections.size())
            return -1;

        vector<vector<int>>graph1(n);
        for(auto v: connections)
        {
            graph1[v[0]].push_back(v[1]);
            graph1[v[1]].push_back(v[0]);
        }
        int num_of_components = 0 ;
        for(int i = 0 ;i<n;++i)
            if(visited[i])
            {
                // dfs_util(i ,n,graph1 , visited );
                bfs_util(i ,graph1 , visited );
                num_of_components++ ;
            }
        return num_of_components-1;
    }
};
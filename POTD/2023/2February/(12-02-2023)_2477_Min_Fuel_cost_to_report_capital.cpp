// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/














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
    long long dfs_u(int node , int parent , int depth,int seats_v , long long int &ans, vector<vector<int>>&graph_1 )
    {
        long long int current_rider  = 1 ;
        for(auto child: graph_1[node])
            if(child!=parent)
                current_rider+=dfs_u(child , node , depth+1,seats_v , ans ,graph_1);
        if(depth==0)
            return ans ;
        
        ans+=(((current_rider/seats_v)*depth) + ((current_rider%seats_v)?1:0)) ;
        return current_rider%seats_v ;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n = roads.size();
        vector<vector<int>> graph_1(n+1);
        for(auto vec : roads)
        {
            graph_1[vec[0]].push_back(vec[1]);
            graph_1[vec[1]].push_back(vec[0]);
        }
        long long int ans = 0 ;
        return dfs_u(0,-1,0,seats,ans,graph_1 );
    }
};




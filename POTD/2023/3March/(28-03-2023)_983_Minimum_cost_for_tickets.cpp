// https://leetcode.com/problems/minimum-cost-for-tickets/description/

















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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> visited(366,false);
        for(auto d : days)
            visited[d] = true ;
        
        vector<int> mincost(366,0) ;
        for(int d = 1 ; d<366 ; ++d)
        {
            if(!visited[d])
            {
                mincost[d] = mincost[d-1];
                continue ; 
            }
            mincost[d] = min({mincost[d-1]+costs[0] , mincost[max(0,d-7)]+costs[1] , mincost[max(0,d-30)]+costs[2] });
        }
        return mincost[365];
    }
};










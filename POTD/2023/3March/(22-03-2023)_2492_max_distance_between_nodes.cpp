// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
















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
    int minScore(int n, vector<vector<int>>& roads) 
    {
        int ans = INT_MAX ;
        vector<vector<pair<int,int>>> graph(n+1)    ;
        for(auto ed : roads)
        {
            graph[ed[0]-1].push_back({ed[1]-1 , ed[2]});
            graph[ed[1]-1].push_back({ed[0]-1 , ed[2]});
        }
        vector<bool>  visited(n,false);
        queue<int> q1 ;
        q1.push(0);
        visited[0] = 1 ;
        while (!q1.empty())
        {
            auto front = q1.front();
            q1.pop();
            for(auto [child , dis] : graph[front])
            {
                ans = min(ans , dis);
                if(!visited[child])
                {
                    visited[child] = true ;
                    q1.push(child);
                }
            }

        }
        

        return ans ;
    }
};











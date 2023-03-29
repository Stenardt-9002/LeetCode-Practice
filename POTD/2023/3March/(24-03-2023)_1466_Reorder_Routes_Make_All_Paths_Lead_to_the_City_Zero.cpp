// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/



















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
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        int ans = 0;
        vector<bool>visisted(n,false);
        vector<vector<int>>front_graph(n);
        vector<vector<int>>back_graph(n);

        queue<int> q1 ;
        q1.push(0);
        visisted[0] = 1 ;
        for(auto ed : connections)
        {
            front_graph[ed[0]].push_back(ed[1]);
            back_graph[ed[1]].push_back(ed[0]);
        }

        //bfs 
        while(q1.size())
        {
            int front = q1.front();
            q1.pop();
            for(auto child : front_graph[front])
                if(!visisted[child])
                {
                    ans++ ;
                    visisted[child] = 1;
                    q1.push(child);
                }

            for(auto child : back_graph[front])
                if(!visisted[child])
                {
                    visisted[child] = 1;
                    q1.push(child);
                }
        }





        return ans ;
    }
};
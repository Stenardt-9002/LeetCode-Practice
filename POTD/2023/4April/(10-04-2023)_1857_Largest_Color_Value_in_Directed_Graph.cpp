// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/













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
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> in_degree_c(n, 0);

        for (auto &edge : edges) 
        {
            graph[edge[0]].push_back(edge[1]);
            in_degree_c[edge[1]]++;
        }
        queue<int> q1;
        for (int i = 0; i < n; i++) 
            if (in_degree_c[i] == 0) 
                q1.push(i);
            

        vector<vector<int>> hash_c(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) 
            hash_c[i][colors[i] - 'a']++;
        
        int ans = 0,visited = 0;
        while (!q1.empty()) 
        {
            int u = q1.front();            q1.pop();            visited++;
            for (int v : graph[u]) 
            {
                for (int c = 0; c < 26; c++) 
                    hash_c[v][c] = max(hash_c[v][c], hash_c[u][c] + (colors[v] == c+'a'));
                
                if (--in_degree_c[v] == 0) 
                    q1.push(v);
            }
            ans = max(ans, *max_element(hash_c[u].begin(), hash_c[u].end()));
        }
        return visited == n ? ans : -1;
    }
};
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        // vector<vector<vector<int>>>graph_1(n) ; 
        vector<vector<pair<int,int>>>graph_1(n) ; 
        queue<vector<int>> ueueq;
        vector<int> finalk_ans(n,-1);
        int cur_dis = 0;

        
        for (auto vec: redEdges)
            graph_1[vec[0]].emplace_back(vec[1],0);

        for (auto vec: blueEdges)
            graph_1[vec[0]].emplace_back(vec[1],1);

        ueueq.emplace(vector<int>{0,0,-1});

        while (!ueueq.empty())
        {
            auto front = ueueq.front();  ueueq.pop();
            if(finalk_ans[front[0]]==-1)
                finalk_ans[front[0]]=front[1];

            for(auto &child: graph_1[front[0]])
                if(front[2]!=child.second && child.first!=-1)
                {
                    ueueq.emplace(vector<int>{child.first , front[1]+1 , child.second});
                    child.first = -1 ;
                }

        }
    
        return finalk_ans ;
    }
};
// class Solution {
// public:
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
//     {
//         vector<vector<vector<int>>>graph_1(2,vector<vector<int>>(n)) ; 
//         queue<vector<int>> ueueq;
//         vector<vector<int>> ans(2,vector<int>(n , 2*n));
//         vector<int> finalk_ans(n,-1);
//         ans[0][0] = ans[1][0] = 0 ;
//         int cur_dis = 0;

        
//         for (auto vec: redEdges)
//             graph_1[1][vec[0]].push_back(vec[1]);

//         for (auto vec: blueEdges)
//             graph_1[0][vec[0]].push_back(vec[1]);

//         ueueq.push({0,1});
//         ueueq.push({0,0});

//         while (!ueueq.empty())
//         {
//             vector<int> front = ueueq.front();  ueueq.pop();
//             int cur_node = front[0];
//             int color = front[1];
//             for(auto child: graph_1[color][cur_node])
//                 if(ans[child][color^1]==n*2)
//                 {
//                     ans[child][color^1] = ans[cur_node][color]+1 ;
//                     ueueq.push({child , color^1});
//                 }

//         }
    
//         for(int i = 0 ; i<n;i++)
//             finalk_ans[i] = min(ans[i][0] , ans[i][1])==n*2 ?-1:min(ans[i][0] , ans[i][1]);
//         return finalk_ans ;
//     }
// };






























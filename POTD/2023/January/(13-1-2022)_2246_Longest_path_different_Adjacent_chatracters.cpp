

// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/




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










    int longestPath(vector<int>& parent, string s) 
    {
        // int n = parent.size()    ;
        // if(n==1)
        //     return 1 ;
        // vector<int>*graph1 = new vector<int>[n];
        // for(int i = 1 ;i<n;i++)
        //     graph1[parent[i]].push_back(i);
        //     // graph1[i].push_back(parent[i]);
    
        // int ans = 0 ;
        // dfs_util(0,s,graph1,ans);
        // return ans ;
        
        
        //bfs 
        int n = parent.size()    ;
        int ans = 1 ;
        vector<int>freq(n),max1(n,1),max2(n,1);
        for(int i = 1;i<n;++i)
            ++freq[parent[i]];
        queue<int> q1 ;
        
        for(int i = 1;i<n;++i)
            if(freq[i]==0)
                q1.push(i);//child node 

        while(!q1.empty() && q1.front()!=0)
        {
            int front1 = q1.front();
            int par = parent[front1];
            q1.pop();
            int cur_depth = 1;
            if(s[front1]!=s[par])
                cur_depth+=max1[front1];
            if(cur_depth>=max1[par])
            {
                max2[par] = max1[par];
                max1[par] = cur_depth ;
            }
            else 
                max2[par] = max(max2[par] , cur_depth);
            if(--freq[par]==0)
            {
                q1.push(par);
                ans = max(ans , max1[par]+max2[par]-1);
            }

        }
        return ans ;

    }
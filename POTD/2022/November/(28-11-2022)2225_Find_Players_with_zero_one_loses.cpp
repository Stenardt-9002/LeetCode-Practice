// https://leetcode.com/problems/find-players-with-zero-or-one-losses/











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





    
    









    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        int maxVar = INT_MIN ;
        for(auto v:matches)
            maxVar = max({maxVar,v[0],v[1]});
        vector<int> indegree(maxVar,-1)    ;
        for(auto v:matches)
            if(indegree[v[0]-1]==-1 || indegree[v[1]-1]==-1)
            {
                indegree[v[0]-1] = 0;
                indegree[v[1]-1] = 0;
            }
            
        
        for(auto v : matches)
            indegree[v[1]-1]++ ;
    
        vector<vector<int>> ans1(2) ;
        for(int i = 0 ; i<maxVar ; i++)
            if(indegree[i]==0)
                ans1[0].push_back(i+1);
            else if (indegree[i]==1)
                ans1[1].push_back(i+1);
        
        return ans1 ;
    }
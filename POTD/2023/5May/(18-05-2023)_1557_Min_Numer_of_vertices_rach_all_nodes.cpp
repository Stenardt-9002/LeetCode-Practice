// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/











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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int>ans , indegree1(n,0) ;
        for(auto i : edges)
            indegree1[i[1]]++ ;
        for(int i =0;i<n;i++)
            if(indegree1[i]==0)
                ans.push_back(i);
        return ans ; 
    }
};






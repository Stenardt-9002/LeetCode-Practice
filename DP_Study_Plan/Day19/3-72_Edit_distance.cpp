// https://leetcode.com/study-plan/dynamic-programming/?progress=x0y0n9pc
















#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



















class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
        for (int i = 0; i <=n; i++)
            dp1[i][0] = i;
        
        for (int i = 0; i <=m; i++)
            dp1[0][i] = i;


        for (int i = 1; i <=n; i++)
            for (int j = 1; j <=m; j++)
                if(word1[i-1]==word2[j-1])
                    dp1[i][j] = dp1[i-1][j-1];
                else 
                    dp1[i][j] = 1+min({dp1[i-1][j-1] , dp1[i][j-1] ,dp1[i-1][j]});

        
        return dp1[n][m];
    }
};















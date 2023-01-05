// https://leetcode.com/study-plan/dynamic-programming/?progress=x0y0n9pc
















#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);







// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) 
//     {
//         int n = text1.length()    ;
//         int m = text2.length()    ;
//         vector<vector<int>>dp1(n+1,vector<int>(2,0));
//         for (int i = 1; i <=n; i++)
//             for (int j = 1; j <=m; j++)
//                 if(text1[i-1]==text2[j-1])
//                     dp1[i][j%2] = 1+dp1[i-1][(j-1)%2];
//                 else 
//                     dp1[i][j%2] = max(dp1[i-1][j%2],dp1[i][(j-1)%2]);


//         return dp1[n][m%2];
        
//     }
// };




class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.length()    ;
        int m = text2.length()    ;
        vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
        for (int i = 1; i <=n; i++)
            for (int j = 1; j <=m; j++)
                if(text1[i-1]==text2[j-1])
                    dp1[i][j] = 1+dp1[i-1][j-1];
                else 
                    dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]);


        return dp1[n][m];
    }
};
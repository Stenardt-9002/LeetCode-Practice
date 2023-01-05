// https://leetcode.com/problems/longest-palindromic-subsequence/description/












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
    int longestPalindromeSubseq(string s) 
    {
        int n = s.length()    ;
        vector<vector<int>>dp1(n,vector<int>(n,0));
        for(int i = 0;i<n;++i)
            dp1[i][i] = 1;
        for(int i = 0;i<n-1;++i)
            if(s[i]==s[i+1])
                dp1[i][i+1] = 2;
            else
                dp1[i][i+1] = 1;
        
        for(int length1 = 2;length1<n;++length1)
            for(int i=0;i<n-length1;i++)
            if(s[i]==s[i+length1])
                dp1[i][i+length1] = 2+dp1[i+1][i+length1-1];
            else
                dp1[i][i+length1] = max(dp1[i+1][i+length1],dp1[i][i+length1-1]);

        return dp1[0][n-1];
    }
};










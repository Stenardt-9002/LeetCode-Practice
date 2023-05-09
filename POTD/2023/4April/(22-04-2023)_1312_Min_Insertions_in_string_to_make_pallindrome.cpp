
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/



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
    int minInsertions(string s) 
    {
        int n = s.length();
        vector<vector<int>>dp1(n+1, vector<int>(n+1,0));
        for(int i = 0 ; i<n;i++)
            for(int j = 0 ; j<n ; j++)
                dp1[i+1][j+1] = ((s[i]==s[n-1-j])?dp1[i][j]+1:max(dp1[i+1][j], dp1[i][j+1]));
        return n-dp1[n][n];
    }
};
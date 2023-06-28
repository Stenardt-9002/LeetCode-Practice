// https://leetcode.com/problems/solving-questions-with-brainpower/







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
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long int>dp1(n+1,0);
        for(int i = n-1; i>=0 ; --i)
            dp1[i] = max(dp1[i+1] ,dp1[min(i+1+questions[i][1] ,n) ]+questions[i][0] );
        return dp1[0];
    }
};
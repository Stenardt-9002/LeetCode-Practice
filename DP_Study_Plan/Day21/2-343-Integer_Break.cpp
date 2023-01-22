

// https://leetcode.com/problems/integer-break/description/








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
    int integerBreak(int n) {
        if(n==1||n==2)
            return 1;
        vector<int>dp1(n+1,1)    ;
        dp1[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if(i!=n)
                dp1[i] = i;
            for (int j = 1; j < i; j++)
                dp1[i] = max({dp1[i] ,dp1[j]*dp1[i-j] });
            
        }
        return dp1[n];
    }
};













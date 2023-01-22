// https://leetcode.com/problems/coin-change-ii/description/?envType=study-plan&id=dynamic-programming-i





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
    int change(int amount, vector<int>& coins) 
    {
        // int n = coins.size()    ;
        // vector<vector<int>>dp1(n+1 , vector<int>(amount+1,0));
        // dp1[0][0] = 1 ;
        // for(int i=1;i<=n;++i)
        // {
        //     dp1[i][0] = 1;
        //     for(int val = 1;val<=amount;++val)
        //         dp1[i][val] = dp1[i-1][val]+(val>=coins[i-1]?dp1[i][val-coins[i-1]]:0);
        // }
        // return dp1[n][amount];

        int n = coins.size()    ;
        vector<int>dp1(amount+1,0);
        dp1[0] = 1;
        for(auto c:coins)
            for(int i=c;i<=amount;i++)
                dp1[i]+=dp1[i-c];

        return dp1[amount];
    }
};
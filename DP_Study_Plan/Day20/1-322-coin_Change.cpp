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
    int coinChange(vector<int>& coins, int amount) {
                int n = coins.size();
        vector<int> dp1(amount+1 , amount+1);
        dp1[0] = 0 ;
        for (int amnt = 1; amnt <amount+1; amnt++)
            for (int &c : coins)
                if(amnt>=c)        
                    dp1[amnt] = min(dp1[amnt],dp1[amnt-c]+1);

        return dp1[amount]>amount?-1:dp1[amount];
    }
};
















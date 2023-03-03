// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/





















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
    int maxProfit(vector<int>& prices) 
    {
            int n = prices.size();
            int max1 = prices[n-1]    ;
            int ans = 0 ;

            for (int i = n-2; i >= 0; i--)
            {
                ans = max(ans , max1-prices[i]);
                max1 = max(max1 , prices[i]);
            }
            return ans ;    
    }
};
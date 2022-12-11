// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/










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








int maxProfit(vector<int>& prices) 
{
    int profit = 0;
    int n = prices.size();
    for (int i = 0; i < n-1; i++)
        if(prices[i+1]>prices[i])
            profit+=(prices[i+1]-prices[i]);
    return profit ;
}








































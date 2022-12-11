// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/







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
    // #excellent explaination by     stake thinking
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

    int n = prices.size();

    vector<vector<int>>dp1(n,vector<int>(3,0));
    //0 index  #state 0 : hold a day off
    //1 index  #state 1 : we buy stock
    //2 index  #state 2 : we sell stock

    dp1[0][0] = 0;
    dp1[0][1] = -prices[0];
    dp1[0][2] = INT_MIN ; //not possible to have sold stock on day 0

    for (int i = 1; i < n; i++)
    {
        dp1[i][0] = max(dp1[i-1][0] , dp1[i-1][2]);//we either didnt have stock on previous day or sold stock on previous day
        dp1[i][1] = max(dp1[i-1][1] , dp1[i-1][0]-prices[i]);
        dp1[i][2] = dp1[i-1][1]+prices[i];
    }
    return max(dp1[n-1][0] , dp1[n-1][2]);
}










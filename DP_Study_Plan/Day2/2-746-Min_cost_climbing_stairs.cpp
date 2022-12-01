// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/










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












int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size();
    if(n==1)
        return cost[0];
    long prev =  cost[0]  ,prev2 = cost[1] ,cur ;
    if(n==2)
        return min(prev , prev2);
    
    for(int i= 2;i<n;++i)
    {
        cur = min(prev,prev2)+cost[i] ;
        prev = prev2;
        prev2 = cur ;
    }
    return min(prev,prev2) ;
}







// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

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


int numRollsToTarget(int n, int k, int target) 
{
    int ylim = max(target , k);
    vector<vector<int>> dp1(n,vector<int>(ylim,0));
    for (int i1 = 0; i1 < k; i1++)
        dp1[0][i1] = 1;

    for(int i1 = 1 ; i1<n ; i1++)
        for (int this_dice = target-1; this_dice >=0; this_dice--)
            for (int sum1 = 1; sum1 <= k && this_dice-sum1>=0; sum1++)
                dp1[i1][this_dice]+=dp1[i1-1][this_dice-sum1] ,dp1[i1][this_dice]%=mod1;
                

    return dp1[n-1][target-1]%mod1;
}




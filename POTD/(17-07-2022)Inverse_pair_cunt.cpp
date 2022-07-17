// https://leetcode.com/problems/k-inverse-pairs-array/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

int MODE1 = 1000000007 ;


int kInversePairs(int n, int k) 
{
    // int MODE1 = 1000000007 ;
    if(n==0 && k==0)
        return 1 ;
    vector<vector<int>>dp1(1003,vector<int>(1003,0));
    dp1[0][0] = 1;
    for (int curn = 1; curn <=n; curn++)
        for (int k1 = 0; k1 <=k; k1++)
        {
            dp1[curn][k1] = (dp1[curn-1][k1] +(k1>0?dp1[curn][k1-1]:0))%MODE1;
            if(k1>=curn)
                dp1[curn][k1] = (MODE1+dp1[curn][k1]-dp1[curn-1][k1-curn] )%MODE1;
        }

    return dp1[n][k];    
}
int kInversePairs1(int n, int k) 
{
    int dp[1001][1001] = {1};

    if (dp[n][k])
        return dp[n][k];
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K) {
            dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
            if (K >= N)
                dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
        }
    return dp[n][k];
}
int main(int argc, char const *argv[])
{
    // cout<<"bruh\n"<<dp[10][0];
    cout<<" "<<kInversePairs1(0,1);
    cout<<" "<<kInversePairs(0,1);

    return 0;
}

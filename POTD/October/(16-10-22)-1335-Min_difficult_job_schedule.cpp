// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule//



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


int minDifficulty(vector<int>& A, int d) 
{

}

int minDifficulty(vector<int>& jobDifficulty, int d) 
{
    int n = jobDifficulty.size(), INT_MaX1 = 1e9;
    int max1;
    if (n < d) 
        return -1;
    vector<int> dp1(n + 1, INT_MaX1);
    dp1[n] = 0;
    for (int len = 1; len <= d; ++len) 
    {
        for (int i = 0; i <= n - len; ++i) 
        {
            dp1[i] = INT_MaX1;
            max1 = 0;
            for (int j = i; j <= n - len; ++j) 
            {
                max1 = max(max1, jobDifficulty[j]);
                dp1[i] = min(dp1[i], max1 + dp1[j + 1]);
            }
        }
    }
    return dp1[0];
}




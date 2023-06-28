// https://leetcode.com/problems/count-ways-to-build-good-strings/









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














int mod1 = 1000000000+7 ;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        
        vector<long long int>dp1(200002,0)    ;
        dp1[zero] = 1;
        dp1[one] += 1;
        for(int i = 1 ; i<=200001-max(zero,one);i++)
        {
            dp1[i+zero]=(dp1[i+zero] + dp1[i])%mod1;
            dp1[i+one] =(dp1[i+one]  + dp1[i])%mod1;
        }
        long long int ans = 0 ;
        for(int i = low;i<=high; i++)
            ans = (ans+dp1[i])%mod1;
        return ans ; 
    }
};
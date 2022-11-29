// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/











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






int numberOfArithmeticSlices(vector<int>& nums) 
{
    int n = nums.size();
    int ans = 0;
    vector<unordered_map<ll , ll>>dp1(n);
    for (int i1 = 1; i1 < n; i1++)
        for (int j1 = 0; j1 < i1; j1++)
        {
            ll diff = nums[i1];diff-=nums[j1];
            ll cnt = dp1[j1].count(diff)?dp1[j1][diff]:0;
            dp1[i1][diff]+=(cnt+1);
            ans+=cnt ;//only size 3 not two
        }

    return ans ;       
    
}
























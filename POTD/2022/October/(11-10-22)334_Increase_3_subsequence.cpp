// https://leetcode.com/problems/increasing-triplet-subsequence/



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



bool increasingTriplet(vector<int>& nums) 
{
         int smallers = INT_MAX ; 
    int medium = INT_MAX ;
    for (auto i : nums)
    {
        if(i<=smallers)
            smallers = i ;
        else if (i<=medium)
            medium = i ;
        else 
            return true ;
    }
    return false ; 
}


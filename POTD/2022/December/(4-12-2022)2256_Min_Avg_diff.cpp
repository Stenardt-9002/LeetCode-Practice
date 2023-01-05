// https://leetcode.com/problems/minimum-average-difference/






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























int minimumAverageDifference(vector<int>& nums) 
{
    ll sum1 = 0;
    int n =nums.size();
    for (int i = 0; i < n; i++)
        sum1+=nums[i];

    int min_ans = INT_MAX ;
    int min_index = -1 ;
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum2+=nums[i];
        sum1-=nums[i];
        ll avg1 = sum2/(i+1);
        ll avg2 = sum1/(n-i-1);
        ll abstract = abs(avg1-avg2);
        if(min_ans>abstract)
        {
            min_ans = abstract ;
            min_index = i ;
        }
    }
    return min_index ;

}








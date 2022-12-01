// https://leetcode.com/problems/delete-and-earn/?envType=study-plan&id=dynamic-programming-i







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






int deleteAndEarn(vector<int>& nums) 
{
        int n = nums.size()    ;
        int min_val = INT_MAX ;
        int max_val = INT_MIN ;
        vector<int>dp1(1e4+1 , 0);
        for(auto i :nums)
        {
            min_val = min(min_val , i)   ;
            max_val = max(max_val , i)   ;
            dp1[i]+=i ;
        }
        int prev2 = 0 , prev = 0;
        for (int i1 = min_val; i1 <=max_val; i1++)
        {
            int tmp = prev2+dp1[i1];
            int tmp2 = max(prev2 , prev);
            prev = tmp ;
            prev2 = tmp2 ;
        }

        return max(prev,prev2);
}





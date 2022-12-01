
// https://leetcode.com/problems/house-robber/?envType=study-plan&id=dynamic-programming-i





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
    



int rob(vector<int>& nums) 
{
    int n = nums.size();
    if(n==1)
        return nums[0];

    if(n==2)
        return max(nums[0],nums[1]);

    int prev = 0 , prev2 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        int tmp = prev ;
        prev = max(prev2+nums[i1],prev);
        prev2 = tmp ;
    }
    return max(prev , prev2);
}
// https://leetcode.com/problems/house-robber-ii/?envType=study-plan&id=dynamic-programming-i





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
        return nums[0] ;
    int ans1 = 0 , prev2 = 0 , prev =  0;
    for(int i = 0 ; i<n-1 ;++i)
    {
        int tmp = max(prev2+nums[i],prev) ;
        prev2 = prev ;
        prev = tmp ;
    }
    ans1 = max(prev , prev2);
    prev =0 , prev2 = 0;
    for(int i = 1 ; i<n ;++i)
    {
        int tmp = max(prev2+nums[i],prev) ;
        prev2 = prev ;
        prev = tmp ;
    }
    ans1 = max({ans1,prev , prev2});
    return ans1 ;
}















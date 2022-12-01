
// https://leetcode.com/problems/maximum-product-subarray/?envType=study-plan&id=dynamic-programming-i











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









int maxProduct(vector<int>& nums) 
{
    auto ans1 = max_element(nums.begin(),nums.end());
    int ans = *ans1 ;
    int n = nums.size();
    int cur_max = 1 , cur_Min = 1 ;
    for (int i = 0; i < n; i++)
    {
        int temp = cur_max ;
        cur_max = max({cur_max*nums[i] , cur_Min*nums[i] , nums[i] });
        cur_Min= min({temp*nums[i] , cur_Min*nums[i] , nums[i]});
        ans = max(ans , cur_max);
    }
    return ans ;






}









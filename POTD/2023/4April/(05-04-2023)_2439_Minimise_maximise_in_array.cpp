// https://leetcode.com/problems/minimize-maximum-of-array/









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









class Solution 
{
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        int n = nums.size();
        long long int sum1 = 0 , ans1 = 0 ;
        for(int i=0;i<n;++i)
        {
            sum1+=nums[i];
            ans1 = max(ans1 , (long long int)(ceil((sum1*1.0)/(i+1))));
        }
        return (int)(ans1);
    }
};
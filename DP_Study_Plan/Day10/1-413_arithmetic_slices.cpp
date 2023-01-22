// https://leetcode.com/problems/arithmetic-slices/











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
    int n = nums.size()    ;
    if(n<3)
        return 0 ;
    
    int ind_cnt =0, diff=0 , ans = 0;
    int prev_diff = nums[1]-nums[0];
    for (int i = 1; i < n-1; i++)
    {
        diff = nums[i+1]-nums[i];
        if(diff==prev_diff)
            ind_cnt++ ;
        else 
        {
            prev_diff = diff ;
            ind_cnt = 0;
        }
        ans+=ind_cnt ;
    }
    
    return ans ;

}



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n = nums.size()    ;
        if(n<3)
            return 0 ;
        int i = 2 , j = 1 ,ans = 0;
        for( ;i<nums.size();++i)
        {
            if(nums[i]-nums[i-1]!=nums[j]-nums[j-1])
                j=i ;
            ans+=(i-j);
        }
        return ans ;
    }
};

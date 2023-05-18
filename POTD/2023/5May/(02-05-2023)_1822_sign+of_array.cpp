// https://leetcode.com/problems/sign-of-the-product-of-an-array/description/









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





    


class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        bool zerodone = false ; 
        bool positive = true ; 
        for(int x=0 ;x<nums.size() && !zerodone ; x++ )
        {
            if(nums[x]==0)
                zerodone = true ;
            else 
                positive = !((!positive)^(nums[x]<0));
        }
        if(zerodone)
            return 0 ; 
        return positive?1:-1;
    }
};












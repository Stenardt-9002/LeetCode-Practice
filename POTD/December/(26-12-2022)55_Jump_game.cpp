// https://leetcode.com/problems/jump-game/description/







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
    bool canJump(vector<int>& nums) {
                int n = nums.size();
        if(n==1)
            return true ;
        if(nums[0]==0)
            return false ;
        int i1,maxReach = nums[0] ;
        for(i1=1;i1<n;i1++)
        {
            if(i1>maxReach)
                return false ;
            if(maxReach>=n)
                return true;
            maxReach = max(maxReach , i1+nums[i1]);
        }
        return true ;  
    }
};
// https://leetcode.com/problems/3sum-closest/



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

const long long int mod2 =  1e18 ;
 int threeSumClosest(vector<int>& nums, int target) 
{
    int n = nums.size();
    
    int new_target = 0;
    int ptr1 = 0 ;
    int ptr2 = 0 ;
    sort(nums.begin(),nums.end());
    int ans1 = nums[0]+nums[1]+nums[2] ;
    for (int i1 = 0; i1 < n-2; i1++)
    {
        new_target = target-nums[i1];
        ptr1 = i1+1 ;ptr2 = n-1;
        //two ptr approach 
        while(ptr1<ptr2)
        {
            if(abs(target-ans1)> abs(target-(nums[ptr1]+nums[ptr2]+nums[i1])) )
                ans1 =nums[ptr1]+nums[ptr2]+nums[i1] ;
                
            if(nums[ptr1]+nums[ptr2]==new_target)
                return target ;
            else if(nums[ptr1]+nums[ptr2]>new_target)
                ptr2-- ;

            else 
                ptr1++ ;
        }
    }
    return ans1 ; 
}

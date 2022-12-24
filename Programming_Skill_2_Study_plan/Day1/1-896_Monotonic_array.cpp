// https://leetcode.com/problems/monotonic-array/?envType=study-plan&id=programming-skills-ii
    







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






bool isMonotonic(vector<int>& nums) 
{
    bool increasing = true, decreasing = true ;    
    int n = nums.size() , i =0 ;
    for (i = 0; i < n-1; i++)
        if(nums[i]>nums[i+1])
            increasing = false ;


    for (i = 0; i < n-1; i++)
        if(nums[i]<nums[i+1])
            decreasing = false ;

    return increasing|| decreasing ;
}



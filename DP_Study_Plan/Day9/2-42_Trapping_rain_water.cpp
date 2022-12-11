// https://leetcode.com/problems/trapping-rain-water/?envType=study-plan&id=dynamic-programming-i






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








int trap(vector<int>& height) 
{
    int n = height.size();
    int start = 0 , end = n-1 ;
    int left_max = 0 , right_max  = 0 ;    
    int ans1 = 0 ;
    while (start<=end)
    {
        if(height[start]<=height[end])
        {
            if(height[start]>=left_max)
                left_max = height[start];
            else 
                ans1+=(left_max-height[start]);
            start++ ;
        }
        else 
        {
            if(height[end]>=right_max)
                right_max = height[end];
            else 
                ans1+=(right_max-height[end]);
            end--;
        }
    }
    return ans1 ;
}







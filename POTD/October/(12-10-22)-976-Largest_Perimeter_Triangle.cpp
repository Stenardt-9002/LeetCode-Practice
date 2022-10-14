// https://leetcode.com/problems/largest-perimeter-triangle/



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


int largestPerimeter(vector<int>& nums) 
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for (int i1 = n-1; i1 >=2; i1--)
        if(nums[i1]<nums[i1-1]+nums[i1-2])
            return nums[i1]+nums[i1-1]+nums[i1-2];

    return 0 ;    


}
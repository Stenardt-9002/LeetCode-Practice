// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/?envType=study-plan&id=dynamic-programming-i










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








int getMaxLen(vector<int>& nums) 
{
    int firstnegative = -1 , zeroplace = -1 , ans1 = 0 , count1 = 0;
    int n = nums.size() ; 
    for (int i = 0; i < n; i++)
    {
        if(nums[i]<0)
        {
            count1++ ;
            if(firstnegative==-1)
                firstnegative = i ;
        }
        if(nums[i]==0)
        {
            count1 = 0;
            firstnegative = -1 ;
            zeroplace = i ;
        }
        else 
        {
            if(count1%2)
                ans1 = max(ans1 , i-firstnegative);
            else 
                ans1 = max(ans1 , i-zeroplace);
        }

    }
    return ans1 ;
}





















// https://leetcode.com/problems/split-array-largest-sum/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

typedef  long long int lld;


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);










bool verify_c(vector<int> nums , int mid , int n , int k)
{
    int i = 0 , sum_cu = 0 , cunt = 1 ;
    while(i<n)
    {
        if(sum_cu+nums[i]>mid)
        {
            sum_cu = 0 ;
            cunt++ ;
        }
        else 
            sum_cu+=nums[i++];
        if(cunt>k)
            return false ;
    }
    return true ;
}









class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        int ans = high ;
        if(k==1)
            return ans;
        while (low<=high)
        {
            int mid = low +(high-low)/2;   
            if(verify_c(nums , mid , n , k))
            {
                ans = mid ; 
                high = mid-1 ;
            }
            else 
                low = mid+1 ;
        }
        return ans ;
    }
};
























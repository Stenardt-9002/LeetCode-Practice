// https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan&id=dynamic-programming-i










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





int maxSubarraySumCircular(vector<int>& nums) 
{
        int n = nums.size();
        int i =0 ,j = n-1 ;
        bool negative = true ;
        for (int temp = 0 ; temp<n ; temp++)
            if(nums[temp]>0)
                negative = false ;

        if(negative)
        {
            int cur_sum = INT_MIN ;
            for(int tmep = 0 ; tmep<n ; tmep++)
                cur_sum = max(cur_sum , nums[tmep]);
            return cur_sum ;
        }
        
        i = 0;
        ll cur_sum = nums[0] , max_sum = nums[0];
        for ( i = 1; i < n; i++)
        {
            cur_sum = max(cur_sum+nums[i] , (ll)nums[i] );
            max_sum = max(max_sum , cur_sum);
        }



        vector<ll> dp1(n,0),dp2(n,0);
        ll sum1 = nums[0];        
        dp1[0] = nums[0];        
        for (i = 1; i < n; i++)
        {
            sum1+=nums[i];
            dp1[i] = max(sum1,dp1[i-1]) ;
        }
        sum1 = nums[n-1];
        dp2[n-1] = sum1 ;
        for (i = n-2; i >= 0; i--)
        {
            sum1+=nums[i];
            dp2[i] = max(sum1,dp2[i+1]) ;
        }
        for (int i1 = 0; i1 < n-1; i1++)
            max_sum = max(max_sum , dp1[i1]+dp2[i1+1]);
        


        return max_sum ;
}






    // int maxSubarraySumCircular(vector<int>& A) {
    //     int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
    //     for (int& a : A) {
    //         curMax = max(curMax + a, a);
    //         maxSum = max(maxSum, curMax);
    //         curMin = min(curMin + a, a);
    //         minSum = min(minSum, curMin);
    //         total += a;
    //     }
    //     return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    // }















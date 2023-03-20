// https://leetcode.com/problems/minimum-time-to-complete-trips/














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
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long int low1 = 1 , high1 = (long long int)(1e14);    
        long long int ans = -1 ;
        int n = time.size();
        if(n==1)
            return ((long long int)(time[0]))*((long long int)(totalTrips)) ;
        while(low1<=high1)
        {
            long long int mid = low1+(high1-low1)/2;
            long long int sum1 = 0;
            for(int i = 0 ; i<n;i++)
                sum1+=(mid/time[i]);
            
            if(sum1>=totalTrips)
            {
                ans = mid ; 
                high1 = mid-1;
            }
            else
                low1 = mid+1 ;
        }
        return ans ;

    }
};
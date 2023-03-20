// https://leetcode.com/problems/koko-eating-bananas/














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
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1 , high = 1<<30 ; 
        int ans = -1;
        while(low<=high)
        {
            int mid1 = low+(high-low)/2;
            int sum1 = 0 ;
            for(auto i : piles)
                sum1+=(ceil(((double)(i))/mid1)) ;
            // cout<<" \ndeg   "<<sum1<<" "<<mid1 ;
            if(sum1>h)
                low = mid1+1 ;
            else 
            {
                ans = mid1 ;
                high = mid1-1 ;
            }
        }
        return ans ;
    }
};


















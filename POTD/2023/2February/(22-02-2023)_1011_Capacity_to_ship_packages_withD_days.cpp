// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/















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





    bool ok_check(vector<int>&weights ,ll allowlimts ,int days,int n)
    {
        int counts = 1 ;
        ll cur_sum = 0 ;
        int i = 0 ;
        while(i<n)
        {
            if(cur_sum+weights[i]<=allowlimts)
                cur_sum+=weights[i++];
            else 
            {
                cur_sum = 0;
                ++counts ;
            }
            if(counts>days)
                return false ;
        }
        // if(allowlimts==2)
        //     cout<<counts<<endl;
        return true ;        

    }


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        ll sum1 = accumulate(weights.begin(),weights.end(),0) ;
        int n = weights.size();
        if(days==1)
            return sum1 ;
        ll ans = 0 ;
        ll low = 0 , high = sum1 ;
        while (low<=high)
        {
            ll mid = low+(high-low)/2;
            if(ok_check(weights ,mid , days,n))
            {
                high = mid-1 ;
                ans = mid ;
            }
            else 
                low = mid+1;
        }
        return ans ;


    }
};
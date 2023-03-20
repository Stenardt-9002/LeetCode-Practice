// https://leetcode.com/problems/kth-missing-positive-number/description/














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
    int findKthPositive(vector<int>& arr, int k) 
    {
        int low =1 ,high = 2002 ; 
        // int nas = -1;

        while(low<=high)   
        {
            int mid = low+(high-low)/2;
            auto pos = lower_bound(arr.begin(),arr.end(),mid);

            int index = pos-arr.begin();
            // cout<<index<<" "<<mid<<endl ;
            if(mid-index==k &&(pos==arr.end() || *pos!=mid))
            {
                // cout<<"DEUG 1 "<<(pos==arr.end());
 
                    return mid ;
                // return -1 ;
            }
            else if(mid-index>k)
                high = mid-1 ;
            else 
                low = mid+1 ;

        }
        return -1 ;
    }
};
// https://leetcode.com/problems/binary-search/submissions/925756987/










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
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0  , high = n-1;    
        while(low<=high)
        {
            int mid = low+(high-low)/2 ; 
            if(nums[mid]==target)
                return mid ; 
            else if(nums[mid]>target)
                high = mid-1 ;
            else 
                low = mid+1 ;
        }
        return -1;
    }
};


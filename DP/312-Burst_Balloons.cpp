// https://leetcode.com/problems/burst-balloons/description/








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

const long long int mod2 =  1e18 ;















    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size()    ;
        vector<int>newarray(n+2,1);
        for(int i = 0 ; i<n;++i)
            newarray[i+1] = nums[i];

        vector<vector<int>>dp1(n+2 , vector<int>(n+2,0));
        for(int length = 1;length<n+1 ;++length)
        {
            for(int left = 1; left<n-length+2 ; left++)
            {
                int right = left+length-1 ;
                for(int last = left ; last<=right;last++)
                    dp1[left][right] = max(dp1[left][right] , dp1[left][last-1]+dp1[last+1][right]+newarray[left-1]*newarray[right+1]*newarray[last]);
            }
        }

        return dp1[1][n];
    
    }
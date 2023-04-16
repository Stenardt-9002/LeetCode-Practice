// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/









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
    int recursive_func(int i , int j , int n ,vector<vector<int>>&A ,vector<vector<int>>&dp1)
    {
        if(dp1[i][j]>0)
            return dp1[i][j];
        if(i==n||j==0)
            return 0 ; 
        int ans = recursive_func(i+1 , j , n , A,dp1) , cur = 0 ;
        for (int k1 = 0; k1 < A[i].size() && k1<j; k1++)
        {
            cur+=A[i][k1];
            ans = max(ans , recursive_func(i+1 ,j-k1-1 ,n , A, dp1)+cur);
        }
        dp1[i][j] = ans ; 
        return ans ;
        
    }


    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size()    ;
        vector<vector<int>>dp1(n+1 , vector<int>(k+1,0));

        return recursive_func(0,k ,n , piles , dp1);

    }
};










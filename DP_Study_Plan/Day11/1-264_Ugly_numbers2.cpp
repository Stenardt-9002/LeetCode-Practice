// https://leetcode.com/problems/ugly-number-ii/








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
    int nthUglyNumber(int n) 
    {
        if(n==1)
            return 1 ;
        int ptr2 = 0 , ptr3 = 0 , ptr5 = 0 ;
        vector<int> dp1(n);
        dp1[0] = 1;
        for(int i = 1 ; i<n ;++i)
        {
            dp1[i] =min({dp1[ptr2]*2 , dp1[ptr3]*3 ,dp1[ptr5]*5});
            if(dp1[i]==dp1[ptr2]*2)
                ptr2++ ;
            if(dp1[i]==dp1[ptr3]*3)
                ptr3++ ;
            if(dp1[i]==dp1[ptr5]*5)
                ptr5++ ;
        }
        return dp1[n-1];
    }
};





















// https://leetcode.com/problems/domino-and-tromino-tiling/description/










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
    int numTilings(int n) 
    {
        vector<int> dp1(n+1,0);
        if(n==1)
            return 1 ;
        if(n==2)
            return 2 ;
        if(n==3)
            return 5 ;
            
        dp1[1] = 1;dp1[2] = 2; dp1[3] = 5 ;
        for (int i = 4; i <=n; i++)
            dp1[i] = dp1[i-1]+2*dp1[i-3];
        // for (int i = 4; i <=n; i++)
        //     for (int j = 1; j < i; j++)
        //         dp1[i] += dp1[i-j]*dp1[j] ;
                
        return dp1[n];
    }
};











// const int MOD1 = 1000000007;

// class Solution 
// {
// public:
//     int numTilings(int n) 
//     {
//         vector<long long int> dp1(5,0);
//         if(n==1)
//             return 1 ;
//         if(n==2)
//             return 2 ;
//         if(n==3)
//             return 5 ;
            
//         dp1[1] = 1;dp1[2] = 2; dp1[3] = 5 ;
//         for (int i = 4; i <=n; i++)
//             dp1[i%5] = (dp1[(i-3)%5]+2*dp1[(i-1)%5])%MOD1;
                
//         return dp1[n%5];
//     }
// };



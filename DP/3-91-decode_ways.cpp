// https://leetcode.com/problems/decode-ways/






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


bool allowed_string(string cur)
{
    if(cur[0]=='0')
        return false ;

    int val = stoi(cur);
    if(val>26|| val<1)
        return false ;
    return true ;

}



int numDecodings(string s) 
{
    if(s[0]=='0')
        return 0 ;
    int n = s.length() ;
    vector<int> dp1(n+1,0);
    if(allowed_string(s.substr(0,1)))
        dp1[0] = 1; 
    else 
        return 0 ;
    if(n==1)
        return dp1[0];
    if(allowed_string(s.substr(0,2)))
        dp1[1]++;
    if(allowed_string(s.substr(1,1)))
        dp1[1]+=dp1[0];


    for (int i1 = 2; i1 < n; i1++)
    {
        if(allowed_string(s.substr(i1,1)))
            dp1[i1]+=dp1[i1-1];
        if(allowed_string(s.substr(i1-1,2)))
            dp1[i1]+=dp1[i1-2];
        
    }
    
    return dp1[n-1];


}


// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/2599448/C%2B%2B-or-DP-or-Related-Problems

// 62. Unique Paths
// 70. Climbing Stairs
// 509. Fibonacci Number
//  639. Decode Ways II.
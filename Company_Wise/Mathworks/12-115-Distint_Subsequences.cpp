// https://leetcode.com/problems/distinct-subsequences/description/











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


int recursive_fun(int starts , int startt , string s , string t , vector<vector<int>>&dp1)
{
    if (startt == t.length())
        return 1 ;
    if(starts==s.length())
        return 0 ;
    if(dp1[starts][startt]!=-1)
        return dp1[starts][startt] ;

    char temp = t[startt];
    int ans1 = 0 ;
    for (int i = starts; i < s.length(); i++)
        if(s[i]==temp)
            ans1+=recursive_fun(i+1 , startt+1 , s , t,dp1);
    dp1[starts][startt] = ans1 ;
    return ans1 ;    
}


// class Solution {
// public:
//     int numDistinct(string s, string t) 
//     {
//         vector<vector<int>>dp1(s.length()+1 , vector<int>(t.length()+1,-1));
//         return recursive_fun(0,0 , s,t,dp1);
//     }
// };



class Solution {
public:
    int numDistinct(string s, string t) 
    {
        ll m = t.length() ; 
        ll n = s.length();
        vector<vector<ll>>dp1(m+1 , vector<ll>(n+1,0));
        for (ll j = 0; j <=n; j++)
            dp1[0][j] = 1 ;
        
        for (ll j = 1; j <=n; j++)
            for (ll i = 1; i <=m; i++)
            {
                if(t[i-1]==s[j-1])
                    dp1[i][j]=dp1[i][j-1]+dp1[i-1][j-1];
                else 
                    dp1[i][j]=dp1[i][j-1];
                dp1[i][j]=dp1[i][j]%(1000000000+7);
            }
        return dp1[m][n];
    }
};



class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int m = t.length() ; 
        int n = s.length();
        vector<vector<int>>dp1(m+1 , vector<int>(n+1,0));
        for (int j = 0; j <=n; j++)
            dp1[0][j] = 1 ;
        
        for (int j = 1; j <=n; j++)
            for (int i = 1; i <=m; i++)
            {
                if(t[i-1]==s[j-1])
                    dp1[i][j]=dp1[i][j-1]+dp1[i-1][j-1];
                else 
                    dp1[i][j]=dp1[i][j-1];
            }
        return dp1[m][n];
    }
};









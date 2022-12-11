// https://leetcode.com/problems/decode-ways/?envType=study-plan&id=dynamic-programming-i











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




int numDecodings(string s) 
{
    int n = s.length();
    vector<int> dp1(n , 0);
    if(s[0]=='0')
        return 0 ;
    if(n==1)
        return 1;
    int num1 = s[0]-'0';
    int num2 = s[1]-'0';

    dp1[0] = 1;
    if(num1*10+num2<=26)
        dp1[1]++;
    if(num2>0)
        dp1[1]++;

    for (int i = 2; i < n; i++)
    {
        num1 = s[i-1]-'0';
        num2 = s[i]-'0';
        int num = num1*10+num2 ;
        if(num<=26&&num1>0)
            dp1[i] += dp1[i-2] ;
        if(num2>0)
            dp1[i]+=dp1[i-1] ;
    }
    return dp1[n-1];

}




int numDecodings(string s) 
{
    int n = s.length();
    if(s[0]=='0')
        return 0 ;
    if(n==1)
        return 1;
    int num1 = s[0]-'0', num2 = s[1]-'0';
    int dp_0 = 1, dp_1 = 0;
    if(num1>0 && num1*10+num2<=26)
        dp_1++;
    if(num2>0)
        dp_1++;

    for (int i = 2; i < n; i++)
    {
        num1 = s[i-1]-'0';
        num2 = s[i]-'0';
        int dp2 = 0;
        int num = num1*10+num2 ;
        if(num<=26&&num1>0)
            dp2+=dp_0 ;
        if(num2>0)
            dp2+=dp_1 ;

        dp_0 = dp_1 ;
        dp_1 = dp2 ;
    }
    return dp_1;

}




























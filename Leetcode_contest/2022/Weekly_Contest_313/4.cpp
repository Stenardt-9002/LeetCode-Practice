

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


int recursive_fun(string s ,int index, vector<int>&dp1)
{
 
    if(dp1[index]!=-1)
        return dp1[index] ;
    int n = s.length();
    int length = 0 ;
    int ans1 = 1;
    
    // while (s!="")
    // {
    for (length = 1; length <=(n-index)/2 ; length++)
        if(s.substr(index,length)==s.substr(index+length,length))
        {
            ans1 = max(ans1 ,1+recursive_fun(s , index+length , dp1));// s.substr(index+length,length);
        }



    
    
    return ans1 ;
}


int deleteString(string s) 
{
    int n = s.length();

    vector<int>dp1(n,-1);
    dp1[n-1] = 1;
    recursive_fun(s , 0 , dp1);
    return dp1[0];
}
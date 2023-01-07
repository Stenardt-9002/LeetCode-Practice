// https://leetcode.com/problems/maximum-deletions-on-a-string/






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

int recursive_fun(string s , int index , vector<int>&dp1)
{
    if(dp1[index]==-1)
    {
        dp1[index] = 1;
        for (int i1 = 1; dp1[index]<=s.size()-i1-index ; i1++)
            if(s.substr(index,i1)==s.substr(index+i1,i1) )
                dp1[index] = max(dp1[index] , 1+recursive_fun(s , index+i1 , dp1) );
        
    }
    return dp1[index];
}

// int deleteString(string s) 
// {
//     int n = s.length();
//     vector<int>dp1(n+1,-1);
//     recursive_fun(s , 0 , dp1);
//     return dp1[0];
// }





//way better approach using LCS


int deleteString(string s) 
{
    int n = s.length();
    vector<vector<int>>dp1(n+1,vector<int>(n+1,0));
    vector<int> ans1(n,1);
    for (int i1 = n-1; i1 >=0; --i1)
        for (int j1 = i1+1; j1 < n; j1++)
        {
            if(s[i1]==s[j1])            
                dp1[i1][j1] = dp1[i1+1][j1+1]+1 ;
            if(dp1[i1][j1]>=j1-i1) // common substring length is more than there distance 
                ans1[i1] = max(ans1[i1],ans1[j1]+1);
        }
        
    

    return ans1[0];
}




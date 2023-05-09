
// https://leetcode.com/problems/restore-the-array/description/






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
    int mod1 = 1000000000+7 ; 



    int numberOfArrays(string s, int k) 
    {
        // int n = s.size();
        // if(n==0)
        //     return 1 ; 
        // if(s[0]=='0')
        //     return 0 ;
        // bool allow = true ;
        // long long int ans = 0 ;
        // for(int i = 1 ; i<=n && allow;i++)
        // {
        //     long long int val = stoll(s.substr(0,i));
        //     if(val>k)
        //     {
        //         allow = false ;
        //         continue ; 
        //     }
        //     long long int temp = numberOfArrays(s.substr(i,n-i),k);
        //     ans =(ans+temp)%mod1;        
        // }
        // return ans ;


        int n = s.size();
        if(n==0)
            return 1 ; 
        vector<long long int> dp1(n+1, 0);
        dp1[n] = 1; 
        for(int j = n-1 ;j>=0 ; j--)
        {
            for(int partition = min(n,j+13); partition>j ; partition--)
            {
                string sub = s.substr(j,partition-j);
                long long int val = stoll(sub);
                if(val<=k && sub[0]!='0')
                    dp1[j]=(dp1[j]+dp1[partition])%mod1; 
            }
        }
        
        return dp1[0] ;
    }
};
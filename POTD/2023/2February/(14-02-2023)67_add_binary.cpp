


// https://leetcode.com/problems/add-binary/description/














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
    string addBinary(string a, string b) {
        string ans = ""   ;
        int n = a.length();
        int m = b.length();
        int carry = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i = 0;i<min(m,n);i++)
        {
            int val = (a[i]-'0')+(b[i]-'0')+carry ; 
            carry = val>>1 ;
            ans+=(to_string(val%2));
        }
        if(m>n)
        {
            for(int i = n;i<m;i++)
            {
                int val = (b[i]-'0')+carry ; 
                carry = val>>1 ;
                ans+=(to_string(val%2));
            }
        }
        else if(m<n)
        {
            for(int i = m;i<n;i++)
            {
                int val = (a[i]-'0')+carry ; 
                carry = val>>1 ;
                ans+=(to_string(val%2));
            }
        }


        if(carry)
            ans+="1";

        reverse(ans.begin(),ans.end());
        return ans ;
    }
};
// https://leetcode.com/problems/reverse-words-in-a-string-iii/




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



    string reverseWords(string s) 
    {
        string empty = "";
        string ans1 = "";
        int n = s.length() ;
        for(int i1 = 0 ; i1<n ;  i1++)
        {
            if(s[i1]!=' ')
            empty += s[i1] ;
            else 
            {
                
                
                
                reverse(empty.begin(),empty.end());
                ans1+=empty ;
                ans1+=" ";
                empty = "";
            }
        }
        // ans1.pop_back();
        reverse(empty.begin(),empty.end());
         ans1+=empty ;
        return ans1 ;
    }

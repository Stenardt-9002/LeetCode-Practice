// https://leetcode.com/problems/break-a-palindrome/




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



    string breakPalindrome(string palindrome) 
    {
        if(palindrome==""||palindrome.size()==1)
            return "";
        int i1=0,n =palindrome.size();
        for(i1=0 ;i1<n/2;i1++)
            if(palindrome[i1]!='a')
            {
                palindrome[i1] = 'a';
                return palindrome ;
            }
        palindrome[n-1] = 'b';
        return palindrome ;
                
    }
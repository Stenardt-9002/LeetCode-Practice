// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan&id=dynamic-programming-ilindromic-subsequence/description/












#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);








class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size()==0)    
            return "";
        if(s.size()==1)    
            return s;
        int start_ind =0 , length_1 = 1;
        for (int i = 0; i < s.length(); )
        {
            int j = i , k = i ;
            while (k<s.length()-1 && s[k+1]==s[k])
                ++k ;
            i  = k+1 ;

            while (k<s.length()-1 && j>0 && s[k+1]==s[j-1])
            {
                ++k ;
                j--;
            }
            int cur_len = k-j+1;
            if(cur_len>length_1)
            {
                start_ind = j ;
                length_1 = cur_len ;
            }
        }
        return s.substr(start_ind , length_1);
        
    }
};






































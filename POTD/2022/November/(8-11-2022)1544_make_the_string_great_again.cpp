
// https://leetcode.com/problems/make-the-string-great/









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












    string makeGood(string s) 
    {
        stack<char> s1 ;
        for(auto char_str : s)
        {
            if(!s1.empty()&& (s1.top()==char_str-'a'+'A' || s1.top()==char_str-'A'+'a' ))
                s1.pop();
            else 
                s1.push(char_str);
        }
        string ans1 = "";
        while(!s1.empty())
        {
            ans1+=s1.top();
            s1.pop();
        }
        reverse(ans1.begin(),ans1.end());
        return ans1 ;
    }
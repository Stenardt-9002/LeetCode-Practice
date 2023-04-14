// https://leetcode.com/problems/removing-stars-from-a-string/










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
    string removeStars(string s) {
        int i = 0 ; 
        int n = s.length();
        // while(i<n)
        // {
        //     if(s[i]=='*')
        //     {
        //         s = s.substr(0,i-1)+s.substr(i+1,n-i);
        //         i-=2 ;
        //         n-=2 ;
        //     }
        //     i++ ;
        // }
        // return s ;
        stack<char> st ;
        for(auto c : s)
        if(c=='*')
            st.pop();
        else    
            st.push(c);
  
        string ans = "";
  
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans ;
    }
};













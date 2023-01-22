// https://leetcode.com/problems/restore-ip-addresses/











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
    void recursion(int cur_ind , int dots , string current_string , string origin ,vector<string>&ans)
    {
        if(dots>4)
            return ;
        if(dots==4 && cur_ind==origin.length())
            ans.push_back(current_string);
        for (int i = 1; i < 4; i++)
        {
            if(cur_ind+i>origin.length())
                break ;
            string temp = origin.substr(cur_ind , i);
            //illegals
            if((temp[0]=='0' && temp.length()>1)||(i==3 && stoi(temp)>255))
                continue ;

            recursion(cur_ind+i , dots+1 , current_string+temp+(dots>=3?"":"."),origin ,ans);
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if(n<4 || n>12)
            return {} ;
        vector<string> ans ;
        recursion(0,0,"",s,ans);
        return ans ;
    }
};





























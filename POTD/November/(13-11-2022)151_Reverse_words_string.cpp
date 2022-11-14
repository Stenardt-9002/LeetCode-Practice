// https://leetcode.com/problems/reverse-words-in-a-string/









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



    string reverseWords(string s) 
    {
        int n = s.length();
        vector<string> words;
        stringstream s1(s);
        string temp1 ,ans1 ;
        while(s1>>temp1)
            words.push_back(temp1);
        n = words.size();
        for(int i1 = n-1;i1>=0;--i1)
        {
            if(i1!=n-1)
                ans1+=" ";
            ans1+=words[i1];
        }
        return ans1 ;
    }






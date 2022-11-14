// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/











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




string removeDuplicates(string s) 
{
    stack<char> s1 ;
    for(auto c : s)
        if(!s1.empty()&& s1.top()==c)
            s1.pop();
        else 
            s1.push(c);

    s = "";
    while (!s1.empty())
    {
        s+=s1.top()    ;
        s1.pop();
    }
    reverse(s.begin(),s.end());
    return s ;
}





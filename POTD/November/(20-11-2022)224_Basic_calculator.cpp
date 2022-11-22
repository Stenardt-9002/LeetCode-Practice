// https://leetcode.com/problems/basic-calculator/






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





int calculate(string s) 
{

    long int ans1 = 0 ,n = s.length();
    long int sign = 1;
    stack<int> s1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        char c = s[i1];
        if(isdigit(c))
        {
            int number = c-'0' ;
            while (i1+1<n && isdigit(s[i1+1]))
                number= 10*number+ (s[i1+1]-'0'),i1++;

            ans1+=number*sign ;
        }
        else if(c=='+')
            sign = 1;
        else if(c=='-')
            sign = -1;
        else if(c=='(')
        {
            s1.push(ans1);
            s1.push(sign);
            ans1 = 0 ;
            sign = 1;
        }
        else if(c==')')
        {
            ans1 = ans1*s1.top();
            s1.pop();
            ans1+=s1.top();
            s1.pop();

        }
    }
    return ans1 ;
    
}



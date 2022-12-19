
// https://leetcode.com/problems/implement-queue-using-stacks/description/







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









bool is_number(string s)
{
    if(s[0]>='0' && s[0]<='9')
        return true ;
    return false ;
}

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int> s1 ;
        for(int i = 0 ; i<tokens.size() ;++i)    
        {

            if(tokens[i]=="/")
            {
                long long int a1 = s1.top();s1.pop();
                long long int b1 = s1.top();s1.pop();
                long long int ans = b1/a1 ;
                s1.push(ans);
            }
            else if(tokens[i]=="*")
            {
                long long int a1 = s1.top();s1.pop();
                long long int b1 = s1.top();s1.pop();
                long long int ans = b1*a1 ;
                s1.push(ans);
            }
            else if(tokens[i]=="+")
            {
                long long int a1 = s1.top();s1.pop();
                long long int b1 = s1.top();s1.pop();
                long long int ans = b1+a1 ;
                s1.push(ans);
            }
            else if(tokens[i]=="-")
            {
                long long int a1 = s1.top();s1.pop();
                long long int b1 = s1.top();s1.pop();
                long long int ans = b1-a1 ;
                s1.push(ans);
            }
            else
            {
                long long int stoint = stoll(tokens[i]);
                s1.push(stoint);
            }
        }
        return s1.top();
    }

};
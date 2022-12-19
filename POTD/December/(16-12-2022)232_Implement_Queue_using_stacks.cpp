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













class MyQueue 
{
public:
stack<int> s1 , s2 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() 
    {
        int ans = this->peek();
        if(s2.empty())
            return -1;
        s2.pop();
        return ans ;
    }
    
    int peek() {
        int ans ;
        if(s2.empty())
        {
            while(!s1.empty()) 
            {
                int tio = s1.top();
                s1.pop();
                s2.push(tio);
            }
        }
        if(s2.empty())
            return -1 ;
        ans = s2.top();
        // s2.pop();
        return ans ; 
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

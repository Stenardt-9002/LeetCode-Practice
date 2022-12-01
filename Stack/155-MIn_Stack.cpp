

//https://leetcode.com/problems/min-stack/






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








class MinStack {
public:
    long long int minEle ;
    stack<long long int> s1 ;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(s1.empty())    
        {
            minEle = val ;
            s1.push(val);
            return ; 
        }
        if(val<minEle)
        {
            long long int push_val = val-minEle;
            push_val+=val ;
            s1.push(push_val);
            minEle = val ;//update and set 2*val-minele which is less than val to mark it 
        }
        else 
            s1.push(val);
        
    }
    
    void pop() 
    {
        if(s1.empty())    
            return ; 
        
        long long int top_ele = s1.top();//check whether they are benched 
        s1.pop();
        if(top_ele<minEle)
            minEle = 2*minEle-top_ele ;//original minele variable
    
    }
    
    int top() 
    {
        if(s1.empty())    
            return -1; 
        
        long long int top_ele = s1.top();//check whether they are benched 
        if(top_ele<minEle)
            return minEle ; //minimum element is inserted at this position
        return top_ele ;
    }
    
    int getMin() 
    {
        if(s1.empty())
            return -1;
        return minEle ;
    }
};













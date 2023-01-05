
// https://leetcode.com/problems/online-stock-span/











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







class StockSpanner {
public:
    stack<pair<int,int>> s1 ;

    StockSpanner() 
    {
    }
    
    int next(int price) 
    {
        int ans1 = 1 ;
        while(!(this->s1.empty()) && (this->s1.top().first<=price) )
        {
            ans1+=this->s1.top().second ;
            this->s1.pop();
        }
        this->s1.push({price ,ans1});
        return ans1 ;
    }
};





















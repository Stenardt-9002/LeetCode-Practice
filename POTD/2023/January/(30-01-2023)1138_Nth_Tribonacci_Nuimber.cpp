








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
    int tribonacci(int n) 
    {
            long int cur1 = 0 , cur2 = 1, cur3 = 1;
        long int next = 2;
        if(n==0)
            return 0 ;
        while(n--)
        {
            next = cur1+cur2+cur3 ;
            cur1 = cur2;
            cur2 = cur3 ;
            cur3 = next ;
        }
        return cur1;    
    }
};
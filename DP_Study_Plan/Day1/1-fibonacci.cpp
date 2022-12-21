
// https://leetcode.com/problems/fibonacci-number/description/?envType=study-plan&id=dynamic-programming-i







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








class Solution 
{
public:
    int fib(int n) 
    {
        if(n==0)
            return 0 ;
        int a = 0 , b = 1;
        int c ;    
        for(int i = 1 ;i<n;++i)
        {
            c = a+b ;
            a = b;
            b = c;
        }
        return b ;
    }
};
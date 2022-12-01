

// https://leetcode.com/problems/climbing-stairs/?envType=study-plan&id=dynamic-programming-i










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






    int climbStairs(int n) 
    {
        long a = 0 , b= 1 , c ;
        while(n--)
        {
            c = a+b ;
            a = b ;
            b = c;
        }
        return c ;
    }






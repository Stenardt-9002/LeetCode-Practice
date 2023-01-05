
// https://leetcode.com/problems/power-of-four/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





    bool isPowerOfFour(int n) 
    {
        if(n<=0)
            return false ;
        int logbase = log10(n)/log10(4);
        if(pow(4,logbase)==n)
            return true ;
        return false ;
    }
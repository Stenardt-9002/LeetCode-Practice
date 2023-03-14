

// https://leetcode.com/problems/count-total-number-of-colored-cells/














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
    long long coloredCells(int n) 
    {
        long long int N = n ;
        long long int ans = N*N ;
        ans += (long long int)((N-1)*(N-1));
        return ans ;
    }
};































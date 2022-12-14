// https://leetcode.com/problems/unique-binary-search-trees/?envType=study-plan&id=dynamic-programming-i









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














int numTrees(int n) 
{
    vector<int> dp1(n+1 ,0)    ;
    dp1[0] =dp1[1]= 1;
    for (int i = 2; i <=n; i++)
        for (int j = 1; j <=i; j++)
            dp1[i]+=(dp1[j-1] * dp1[i-j]);

    return dp1[n]    ;
}














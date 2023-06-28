// https://leetcode.com/problems/matrix-diagonal-sum/description/







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
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int ans = 0 ; 
        for(int i = 0 ; i<n ; i++)
            ans+=(mat[i][i]+mat[i][n-1-i] );
        if(n%2)
            ans-=mat[n/2][n/2];
        return ans ; 
    }
};

// https://leetcode.com/problems/minimum-falling-path-sum/description/









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




int minFallingPathSum(vector<vector<int>>& matrix) 
{
    int n = matrix.size()    ;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int left =INT_MAX ,right = INT_MAX,top = INT_MAX;
            if(j>0)
             left = matrix[i-1][j-1];
            if(j<n-1)
             right = matrix[i-1][j+1];
            top = matrix[i-1][j];
            matrix[i][j]+=min({top,left,right});
        }
        


    int ans = INT_MAX ;
    for (int i = 0; i < n; i++)
        ans = min(ans , matrix[n-1][i]);
    
    return ans ;

}
























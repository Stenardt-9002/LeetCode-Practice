
// https://leetcode.com/problems/minimum-falling-path-sum/






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


class Solution 
{
    public:
        const int SHORT_MAX = 1<<15-1;
        int minFallingPathSum(vector<vector<int>>& matrix) 
        {
            short n = matrix.size()    ;
            for (short i = 1; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    short left =SHORT_MAX ,right = SHORT_MAX,top = SHORT_MAX;
                    if(j>0)
                    left = matrix[i-1][j-1];
                    if(j<n-1)
                    right = matrix[i-1][j+1];
                    top = matrix[i-1][j];
                    matrix[i][j]+=min({top,left,right});
                }
                


            int ans = INT_MAX ;
            for (short i = 0; i < n; i++)
                ans = min(ans , matrix[n-1][i]);
            
            return ans ;    
        }
};
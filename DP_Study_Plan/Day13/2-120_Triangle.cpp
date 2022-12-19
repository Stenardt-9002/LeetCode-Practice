
// https://leetcode.com/problems/triangle/?envType=study-plan&id=dynamic-programming-i






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






int minimumTotal(vector<vector<int>>& triangle) 
{
        int n = triangle.size()        ;
        if(n==0)
            return 0 ;
        
        vector<vector<int>>dp1 ;
        for (int i = 0; i < n; i++)
        {
            int size = triangle[i].size();
            vector<int>temp1(size , INT_MAX);
            dp1.push_back(temp1);
        }
        
        dp1[0][0] = triangle[0][0] ;
        if (n==1)
            return dp1[0][0];

        for (int i = 1; i < n; i++)
        {
            int sn = triangle[i].size();
            dp1[i][0] = triangle[i][0]+dp1[i-1][0];
            dp1[i][sn-1] = triangle[i][sn-1]+dp1[i-1][sn-2];
            for (int j = 1; j < sn-1; j++)
                dp1[i][j] = min(dp1[i-1][j] ,dp1[i-1][j-1] ) + triangle[i][j];
            
        }
        
        int ans = INT_MAX ;
        for (int i = 0; i < n; i++)
            ans = min(ans , dp1[n-1][i]);

        return ans ;
}
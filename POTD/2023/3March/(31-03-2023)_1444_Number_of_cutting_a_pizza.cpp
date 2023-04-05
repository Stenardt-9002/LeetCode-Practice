// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/










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























const int MOD1 = 1000000007;
long long int dfs_u(long long int n ,long long int m , long long int startr ,long long int startc ,long long  int k , vector<vector<vector<long long int>>>&dp1 ,vector<vector<long long int>>&constant_sum )
{
    if(constant_sum[startr][startc]==0)
        return 0 ;//no sum left in corner
    if(k==1)
        return 1;
    if(dp1[k][startr][startc]!=-1)
        return dp1[k][startr][startc];
    
    long long int ans = 0 ;
    for(long long int row = startr+1 ;row<n;row++)
        if(constant_sum[startr][startc] - constant_sum[row][startc]>0)
        ans = (ans+dfs_u(n,m,row,startc ,k-1,dp1,constant_sum))%MOD1;
    for(long long int col = startc+1 ;col<m;col++)
        if(constant_sum[startr][startc] - constant_sum[startr][col]>0)
        ans = (ans+dfs_u(n,m,startr,col ,k-1,dp1,constant_sum))%MOD1;
        // if(ans<0)
        //     ans+=1000000007;
        return dp1[k][startr][startc]=ans ;
}

class Solution 
{
public:
    int ways(vector<string>& pizza, int k) {
        long long int n = pizza.size();
        long long int m = pizza[0].size();
        vector<vector<vector<long long int>>>dp1(k+1 ,vector<vector<long long int>>(n , vector<long long int>(m , -1)) );
        vector<vector<long long int>>constant_sum(n+1 , vector<long long int>(m+1 , 0));


        for(long long int rows = n-1 ; rows>=0 ; --rows)
            for(long long int cols = m-1 ; cols>=0 ; --cols)
                constant_sum[rows][cols] = constant_sum[rows+1][cols] +constant_sum[rows][cols+1]-constant_sum[rows+1][cols+1]+(pizza[rows][cols]=='A');

        return dfs_u(n , m , 0 ,0,k , dp1 ,constant_sum )%MOD1;
    }
};  








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


int count(int curr , int curc ,int n , int m ,vector<vector<int>> grid)
{
    int num_zeros =0 ,number_ones = 0;
    for (int i1 = 0; i1 < n; i1++)
        if(grid[i1][curc]==1)
            number_ones++;
        else 
            num_zeros++ ;
    
    for (int i1 = 0; i1 < m; i1++)
        if(grid[curr][i1]==1)
            number_ones++;
        else 
            num_zeros++ ;
    
    
    return number_ones-num_zeros ;


}



vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp1(n,vector<int>(m,0));
    vector<int> numrow(n,0);
    vector<int>zerorow(n,0);
    vector<int> numcol(m,0);
    vector<int>zerocol(m,0);

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(grid[i1][j1]==1)
                numrow[i1]++ ,numcol[j1]++;
            else 
                zerorow[i1]++ , zerocol[j1]++ ;
    
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            dp1[i1][j1] = numrow[i1]+numcol[j1]-zerocol[j1]-zerorow[i1];
    return dp1 ;
}
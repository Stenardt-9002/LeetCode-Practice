// https://leetcode.com/problems/toeplitz-matrix/





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






bool isToeplitzMatrix(vector<vector<int>>& matrix) 
{
    int n = matrix.size()    ;
    int m = matrix[0].size();

    for (int i1 = 0; i1 < m; i1++)
        for (int j1 = 1; j1 < n && i1+j1<m; j1++)
            if(matrix[0][i1]!=matrix[j1][i1+j1])
                return false ;



    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 1; j1 < m && i1+j1<n; j1++)
            if(matrix[i1][0]!=matrix[i1+j1][j1])
                return false ;
    
    return true ;
}




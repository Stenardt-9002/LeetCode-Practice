// https://leetcode.com/problems/sort-the-matrix-diagonally/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void rotate(vector<vector<int>>& matrix) 
{

    int n = matrix.size();
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = i1+1; j1 < n; j1++)
            swap(matrix[i1][j1] , matrix[j1][i1]);
    

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 <n/2; j1++)
            swap(matrix[i1][j1] , matrix[i1][n-1-j1] );
    


}






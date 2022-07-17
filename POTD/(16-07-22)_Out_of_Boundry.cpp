// https://leetcode.com/problems/out-of-boundary-paths/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

int MODE1 = 1000000007 ;

// int util_func(int row , int col , int maxMove , int x , int y , int moves , vector<vector<vector<int>>>&dp1)
// {
//     if(x<0 || y<0 || x>=row || y>=col)
//         return 1 ;

//     if(moves == maxMove)
//         return 0  ;

//     if(dp1[moves][x][y]!=-1)
//         return dp1[moves][x][y]%MODE1 ;

//     int tempVal = 0 ;
//     tempVal+=(util_func(row,col,maxMove,x,y-1,moves+1,dp1)%MODE1);
//     tempVal+=(util_func(row,col,maxMove,x,y+1,moves+1,dp1)%MODE1);
//     tempVal+=(util_func(row,col,maxMove,x+1,y,moves+1,dp1)%MODE1);
//     tempVal+=(util_func(row,col,maxMove,x-1,y,moves+1,dp1)%MODE1);
//     dp1[moves][x][y] = tempVal ;

//     return dp1[moves][x][y]%MODE1 ;
// }


int util_func(int m , int n , int x , int y , int moves , vector<vector<vector<int>>>&dp1)
{
        if(x<0 || y<0 || x==m || y==n)
            return 1 ;

        if(moves==0)
            return 0  ;

        if(dp1[x][y][moves]!=-1)
            return dp1[x][y][moves];

        int tempVal = 0 ;
        tempVal+=(util_func(m,n,x,y-1,moves-1,dp1)%MODE1);
        tempVal = tempVal%MODE1 ;
        tempVal+=(util_func(m,n,x,y+1,moves-1,dp1)%MODE1);
        tempVal = tempVal%MODE1 ;
        tempVal+=(util_func(m,n,x+1,y,moves-1,dp1)%MODE1);
        tempVal = tempVal%MODE1 ;
        tempVal+=(util_func(m,n,x-1,y,moves-1,dp1)%MODE1);
        tempVal = tempVal%MODE1 ;
        return dp1[x][y][moves] = tempVal ;
            return dp1[moves][x][y]%MODE1 ;

}



int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
{
    vector<vector<vector<int>>> dp1(54 , vector<vector<int>>(54,vector<int>(54,-1)));
    return util_func(m,n,startRow,startColumn,maxMove,dp1);

    return dp1[maxMove][m][n]%MODE1 ; 
}



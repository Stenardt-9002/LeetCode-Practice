// // https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


// #include <bits/stdc++.h>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>


// using namespace std;
// using namespace __gnu_pbds ;
// typedef  long long ll1d;

// bool bool_safe(int x,int y, int m ,int n)
// {
//     return (x>=0&&y>=0&&x<m&&y<n) ;
// }

// int directionx[4] = {0,-1,0,1};
// int directiony[4] = {-1,0,1,0};

// int dfs_func(vector<vector<int>> matrix,vector<vector<int>> &length_array,int i1,int j1,int m,int n)
// {
//     if(length_array[i1][j1]!=-1)
//         return length_array[i1][j1];
//     int max1 = 1,cur_len ;
//     for (int x = 0; x < 4; x++)
//     {
//         int newx = i1+directionx[x] ;
//         int newy = j1+directiony[x] ;
//         if(bool_safe(newx,newy,m,n)&&(matrix[newx][newy]>matrix[i1][j1] ))
//             max1 = max(max1,1+dfs_func(matrix,length_array,newx,newy,m,n));
//     }
//     length_array[i1][j1] = max1 ;
//     return max1 ;
// }


// int longestIncreasingPath(vector<vector<int>>& matrix) 
// {
//     int m = matrix.size() ;
//     int n = matrix[0].size() ;
//     if(m==0)
//         return 0 ;
//     vector<vector<int>> length_array(m,vector<int>(n,-1));//caching
//     int curent_length = 0,macx_lenth = -1;
//     for (int i1 = 0; i1 < m; i1++)
//         for (int j1 = 0; j1 < n; j1++)
//             macx_lenth = max(dfs_func(matrix,length_array, i1,j1,m,n),macx_lenth );
        
//     return macx_lenth ;
// }

// int main(int argc, char const *argv[])
// {

//     int m ,n ;
//     cin>>m>>n ;
//     vector<vector<int>> matrix(m,vector<int>(n,0)) ;
//     for (int i = 0; i < m; i++)
//         for (int k = 0; k < n; k++)
//             cin>>matrix[i][k];
//     cout<<endl ;
//     for (int i = 0; i < m; i++)
//     {
//         for (int k = 0; k < n; k++)
//             cout<<matrix[i][k]<<" ";
//         cout<<"\n";
//     }
//     cout<<longestIncreasingPath(matrix)<<endl;
//     return 0;
// }








































































// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

bool bool_safe(int x,int y, int m ,int n)
{
    return (x>=0&&y>=0&&x<m&&y<n) ;
}
vector<vector<int>> dp1(202,vector<int>(202,0));

int dfs_func(vector<vector<int>> matrix,int i1,int j1,int m,int n,int prev)
{
    if(!bool_safe(i1,j1,m,n) || matrix[i1][j1]<=prev )
        return 0;

    if(dp1[i1][j1]!=0)
        return dp1[i1][j1];

    dp1[i1][j1] = 1+max({dfs_func(matrix,i1+1,j1,m,n,matrix[i1][j1]) , dfs_func(matrix,i1-1,j1,m,n,matrix[i1][j1]) , dfs_func(matrix,i1,j1+1,m,n,matrix[i1][j1]) , dfs_func(matrix,i1,j1-1,m,n,matrix[i1][j1])});
    return dp1[i1][j1] ;
}


int longestIncreasingPath(vector<vector<int>>& matrix) 
{
    int m = matrix.size() ;
    int n = matrix[0].size() ;
    for (int i1 = 0; i1 < m; i1++)
        for (int j1 = 0; j1 < n; j1++)
            dp1[i1][j1] = 0 ;
    
    if(m==0)
        return 0 ;
    
    int macx_lenth = 0;
    for (int i1 = 0; i1 < m; i1++)
        for (int j1 = 0; j1 < n; j1++)
            macx_lenth = max(macx_lenth,dfs_func(matrix,i1,j1,m,n,-1) );
        
    return macx_lenth ;
}

int main(int argc, char const *argv[])
{

    int m ,n ;
    cin>>m>>n ;
    vector<vector<int>> matrix(m,vector<int>(n,0)) ;
    for (int i = 0; i < m; i++)
        for (int k = 0; k < n; k++)
            cin>>matrix[i][k];
    // cout<<endl ;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int k = 0; k < n; k++)
    //         cout<<matrix[i][k]<<" ";
    //     cout<<"\n";
    // }
    cout<<longestIncreasingPath(matrix)<<endl;
    return 0;
}













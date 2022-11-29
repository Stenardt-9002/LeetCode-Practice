// https://leetcode.com/problems/word-search/









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


bool dfs_util(int curx , int cury , int n , int m ,vector<vector<char>>& board, string word , int index)
{
    if(curx<0||cury<0||curx>=n||cury>=m ||board[curx][cury]!=word[index])
        return false ;
    if(index == word.length()-1)
        return true ;
    bool ans_wer = false ;
    char orig = board[curx][cury] ;
    board[curx][cury] = '.';
    ans_wer = dfs_util(curx+1 , cury , n , m , board , word , index+1)||
    dfs_util(curx-1 , cury , n , m , board , word , index+1)||
    dfs_util(curx , cury+1 , n , m , board , word , index+1)||
    dfs_util(curx , cury-1 , n , m , board , word , index+1);


    board[curx][cury] = orig ;
    return ans_wer ;
}



bool exist(vector<vector<char>>& board, string word) 
{
    int n = board.size();
    int m = board[0].size(); 
    int length = word.length();
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(dfs_util(i1,j1,n,m,board ,word , 0))
                return true ;

    return false ;        
}





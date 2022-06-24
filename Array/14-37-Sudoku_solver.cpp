
// https://leetcode.com/problems/sudoku-solver/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



bool bruh_safe(int n , int row , int col , int cur_val , vector<vector<int>>& board)
{
  int i1 , j1 ;
  //check column
  for (i1 = 0; i1 < n; i1++)
    if(board[row][i1]==cur_val)
      return false ;

  //check row
  for (i1 = 0; i1 < n; i1++)
    if(board[i1][col]==cur_val)
      return false ;

  //check column
  int starow = row - (row%3);
  int starcol = col - (col%3);
  for (i1 = 0; i1 < 3; i1++)
    for(j1 = 0 ; j1 < 3 ; j1++)
      if(board[starow+i1][starcol+j1]==cur_val)
        return false ;

    return true ;
}


bool solve_sudoku_util(int n , int row , int col , vector<vector<int>>& board)
{
    if(row==n-1&&col==n)
      return true ;

    if(col==n)
      row++ , col = 0;

    if(board[row][col]!=-1)
      return solve_sudoku_util(n,row,col+1,board);

    //for all posible values
    for(int num = 1 ;num<=n ; num++)
    {
      if(bruh_safe(n,row,col,num,board))
      {
        board[row][col] = num ;
        if(solve_sudoku_util(n,row,col+1,board))
          return true ;
      }
      board[row][col]=-1;
    }

    return false ;
}


void solveSudoku(vector<vector<char>>& board)
{
  int n = board.size() ,i1,j1;
  std::vector<std::vector<int> > matrix1(n,vector<int>(n,-1));
  for (i1 = 0; i1 < n;i1++)
    for (j1 = 0; j1 < n;j1++)
        if(board[i1][j1]!='.')
          matrix1[i1][j1]=board[i1][j1]-'0';

  // for (i1 = 0; i1 < n;i1++)
  //   for (j1 = 0; j1 < n;j1++)
  //       if(board[i1][j1]=='.')
  //         matrix1[i1][j1]=-1;
  //       else
  //         matrix1[i1][j1]=board[i1][j1]-'0';
  solve_sudoku_util(n,0,0,matrix1);
  for (i1 = 0; i1 < n;i1++)
  {
    for (j1 = 0; j1 < n;j1++)
      cout<<" "<<matrix1[i1][j1];
    cout<<endl ;
  }
      // board[i1][j1] = matrix1[i1][j1]+48;
        // if(board[i1][j1]!='.')

}


int main(int argc, char const *argv[])
{
  int i1, j1 , n = 9;
  char temp1 ;
  std::vector<std::vector<char> > matrix1(n,vector<char>(n,'.'));
  for (i1 = 0; i1 < n; i1++)
    for (j1 = 0; j1 < n; j1++)
      cin>>matrix1[i1][j1];

      solveSudoku(matrix1);

      for (i1 = 0; i1 < n;i1++)
      {
        cout<<"\n";
        for (j1 = 0; j1 < n;j1++)
          cout<<" "<<matrix1[i1][j1];
      }
  return 0;

}

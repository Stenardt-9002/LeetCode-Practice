

// https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



bool isValidSudoku(vector<vector<char>>& board)
{
  int n = 9 ,i1,j1;
  std::vector<std::vector<int> > matrix1(n,vector<int>(n,0));
  for (i1 = 0; i1 < n;i1++)
    for (j1 = 0; j1 < n;j1++)
        if(board[i1][j1]=='.')
          matrix1[i1][j1]=-1;
        else
          matrix1[i1][j1]=board[i1][j1]-'0';

  for (i1 = 0; i1 < n;i1++)
  {
    cout<<"\n";
    for (j1 = 0; j1 < n;j1++)
      cout<<" "<<matrix1[i1][j1];
  }
  cout<<endl<<endl;
  std::vector<bool> validate(n,false);
  //each row
  for(i1=0;i1<n;i1++)
  {
    for(j1=0;j1<n;j1++)
      validate[j1]=false;

    for(j1=0;j1<n;j1++)
      if(matrix1[i1][j1]!=-1)
      {
        if(!validate[matrix1[i1][j1]-1])
          validate[matrix1[i1][j1]-1] = true ;
        else
          return false ;

          // {
          //   cout<<i1<<" "<<j1;
          //   return false ;
          // }
      }
  }
  //each column
  for(i1=0;i1<n;i1++)
  {
    for(j1=0;j1<n;j1++)
      validate[j1]=false;

    for(j1=0;j1<n;j1++)
      if(matrix1[j1][i1]!=-1)
      {
        if(!validate[matrix1[j1][i1]-1])
          validate[matrix1[j1][i1]-1] = true ;
        else
          return false ;

          // {
          //   cout<<i1<<" "<<j1;
          //   return false ;
          // }
      }
  }



  //each block
  int BLOCK_SIZE = 3 ;
  for(i1=0;i1<n;i1+=3)
  {
    for(j1=0;j1<n;j1+=3)
    {
      for(int t=0;t<n;t++)
        validate[t] = false ;

      for(int x = 0;x<BLOCK_SIZE;x++ )
      {
        for (int y = 0; y < BLOCK_SIZE; y++)
        {
          if(matrix1[i1+x][j1+y]!=-1)
          {
            if(!validate[matrix1[i1+x][j1+y]-1])
              validate[matrix1[i1+x][j1+y]-1] = true ;
            else
            {
              // cout<<i1+x<<" "<<j1+y;
              return false ;
            }
          }
        }
      }
    }
  }


  return true ;
}


int main(int argc, char const *argv[])
{
  int i1, j1 , n = 9;
  char temp1 ;
  std::vector<std::vector<char> > matrix1(n,vector<char>(n,'.'));
  for (i1 = 0; i1 < n; i1++)
    for (j1 = 0; j1 < n; j1++)
      cin>>matrix1[i1][j1];

      // for (i1 = 0; i1 < n;i1++)
      // {
      //   cout<<"\n";
      //   for (j1 = 0; j1 < n;j1++)
      //     cout<<" "<<matrix1[i1][j1];
      // }
      cout<<isValidSudoku(matrix1);
  return 0;
}

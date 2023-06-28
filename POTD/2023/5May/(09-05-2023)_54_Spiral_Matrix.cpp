// https://leetcode.com/problems/spiral-matrix/description/










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







class Solution {
public:
  


  
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int starti = 0 ,startj = 0 ;
        int lengthx = n-1 ,lengthy = m-1;     
        vector<int>ans ;
        while(starti<=lengthx && startj<=lengthy)
        {
            for(int i = startj ; i<=lengthy ; i++)
                ans.push_back(matrix[starti][i]);
            starti++;
            if(!(starti<=lengthx && startj<=lengthy))
                break ;
            for(int i = starti ; i<=lengthx;i++)
                ans.push_back(matrix[i][lengthy]);
            lengthy-- ;
            if(!(starti<=lengthx && startj<=lengthy))
                break ;
            for(int i = lengthy ; i>=startj;i--)
                ans.push_back(matrix[lengthx][i]);
            lengthx-- ;
            if(!(starti<=lengthx && startj<=lengthy))
                break ;
            for(int i = lengthx ; i>=starti;i--)
                ans.push_back(matrix[i][startj]);
            startj++ ;
        }

        return ans ;
    }
};
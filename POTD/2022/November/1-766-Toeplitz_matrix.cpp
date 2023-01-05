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




vector<int> findBall(vector<vector<int>>& grid) 
{
        int n = grid.size(),m = grid[0].size();
        vector<int> ans1 ;

        for (int i1 = 0; i1 < m; i1++)
        {
            int ptr1 = i1,ptr2  ;
            for (int j1 = 0; j1 < n; j1++)
            {
                ptr2 = ptr1+grid[j1][ptr1];//-1 go left +1 go right
                if(ptr2<0 || ptr2>=m || grid[j1][ptr1]!=grid[j1][ptr2])
                {
                    ptr1 =-1 ;
                    j1 = n+1;
                }
                else 
                    ptr1 = ptr2;

                
            }
            ans1.push_back(ptr1)        ;
        }

        return ans1 ;
}



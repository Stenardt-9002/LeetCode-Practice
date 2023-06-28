// https://leetcode.com/problems/spiral-matrix-ii/









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
    vector<vector<int>> generateMatrix(int n) 
    {
        int left = 0 , right = n-1,top =0 ,bottom = n-1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        int i = 1;
        while(left<=right && top<=bottom)
        {
            for(int x = left ; x<=right;x++)
                ans[top][x] = i++ ;
            top++ ; 
            if(!(left<=right && top<=bottom))
                break;
            for(int x = top ; x<=bottom;x++)
                ans[x][right] = i++ ;
            right-- ;
            if(!(left<=right && top<=bottom))
                break; 
            for(int x = right ; x>=left;x--)
                ans[bottom][x] = i++ ;
            bottom--; 
            if(!(left<=right && top<=bottom))
                break;
            for(int x = bottom ; x>=top;x--)
                ans[x][left] = i++ ;
            left++ ; 

        }
        return ans ;
    }
};
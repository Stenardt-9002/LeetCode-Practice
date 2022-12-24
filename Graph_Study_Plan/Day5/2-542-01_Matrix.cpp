// https://leetcode.com/problems/01-matrix/description/








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


static int arrx[] = {0,-1,0,1,0};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size()    ;
        int m = mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q1 ;
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
                if(mat[i][k]==0)
                {
                    q1.push({i,k});
                    visited[i][k] = true ;
                }
        int steps = 0 ;
        while (!q1.empty())
        {
            int size = q1.size();
            ++steps ;
            while(size--)
            {
                pair<int,int> front = q1.front();
                q1.pop();
                for (int i = 0; i < 4; i++)
                {
                    int newx = front.first+arrx[i];
                    int newy = front.second+arrx[i+1];
                    if(newx<0||newx>=n||newy<0||newy>=m || visited[newx][newy])
                        continue;

                    mat[newx][newy] = steps ;
                    visited[newx][newy] = true ;
                    q1.push({newx,newy});
                }
            }

        }
        return mat ;
    }
};
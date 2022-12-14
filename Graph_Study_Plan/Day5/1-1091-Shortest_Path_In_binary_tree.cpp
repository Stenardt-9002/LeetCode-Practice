// https://leetcode.com/problems/shortest-path-in-binary-matrix/?envType=study-plan&id=graph-i








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







static int arrx[] = {-1,-1,-1,0,0,1,1,1};
static int arry[] = {-1,0,1,-1,1,-1,0,1};



int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{

    int n = grid.size();
    if(grid[0][0]==1)
        return -1 ;
    
    queue<pair<int,int>> q1 ;
    q1.push({0,0});
    grid[0][0] = 1;
    int distance = 0 ;
    while (!q1.empty())
    {
        int qsize = q1.size();
        ++distance ;
        while (qsize--)
        {   
            pair<int,int> p = q1.front();
            q1.pop();
            if(p.first==n-1 && p.second==n-1)
                return distance ;
            for (int i = 0; i < 8; i++)
            {
                int newx = p.first+arrx[i];
                int newy = p.second+arry[i];
                if(newx>=0 && newy>=0 && newx<n&& newy<n && grid[newx][newy]==0)
                {
                    grid[newx][newy] = 1;
                    q1.push({newx,newy});
                }
            }
            
        }
    }
    


    return -1 ;
}










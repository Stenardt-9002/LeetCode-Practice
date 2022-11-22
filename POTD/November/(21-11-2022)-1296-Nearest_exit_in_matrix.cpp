    
    






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







int arrx[] = {0,-1,0,1,0};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
{
    int n = maze.size();
    int m = maze[0].size();

    queue<vector<int>> q1 ;
    int ans1 = INT_MAX ;
    q1.push({entrance[0],entrance[1],0});
    while (!q1.empty())
    {
        vector<int> front1 = q1.front();
        q1.pop();
        int curx = front1[0];
        int cury = front1[1];
        int di1s = front1[2];
        if((curx==0 || cury==0||curx==n-1||cury==m-1)&&(!(curx==entrance[0]&&cury==entrance[1])))
            return di1s;

        for(int i1 = 0 ;i1<4;i1++)
        {
            int new_x = curx+arrx[i1];
            int new_y = cury+arrx[i1+1];
            if(new_x<0||new_x>=n||new_y<0||new_y>=m||maze[new_x][new_y]=='+')
                continue ;
            else 
            {
                q1.push({ new_x, new_y , di1s+1});
                maze[new_x][new_y] = '+';//visited
            }
        }
    }
    return -1 ;
}

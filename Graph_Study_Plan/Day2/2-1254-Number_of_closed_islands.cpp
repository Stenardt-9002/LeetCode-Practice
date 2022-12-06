// https://leetcode.com/problems/number-of-closed-islands/










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


// short fill (short srcx , short srcy , short n , short m , vector<vector<int>> &graph)
// {
//     if(srcx<0||srcy<0||srcx>=n || srcy>=m || graph[srcx][srcy]==1)
//         return 0 ;
//     graph[srcx][srcy] = 1;
//     return 1 + fill(srcx+1 , srcy , n ,m , graph)+fill(srcx, srcy+1 , n ,m , graph)+fill(srcx-1 , srcy , n ,m , graph)+fill(srcx , srcy-1 , n, m , graph);
// }

void fill (short srcx , short srcy , short n , short m , vector<vector<int>> &graph)
{
    if(srcx<0||srcy<0||srcx>=n || srcy>=m || graph[srcx][srcy])
        return  ;
    graph[srcx][srcy] = 1;
    fill(srcx+1 , srcy , n ,m , graph);
    fill(srcx, srcy+1 , n ,m , graph);
    fill(srcx-1 , srcy , n ,m , graph);
    fill(srcx , srcy-1 , n, m , graph);
}




int closedIsland(vector<vector<int>>& grid) 
{
    short n = grid.size() ,m = grid[0].size();
    for (short i = 0; i < n; i++) for (short j = 0; j < m; j++)
            if((i==0 || j==0 ||i==n-1||j==m-1 ))    
                fill(i,j,n,m,grid);

    short answer = 0 ;
    for (short i = 0; i < n; i++) for (short j = 0; j < m; j++)
        if(grid[i][j]==0)
        {
            answer++ ;
            fill(i,j,n,m,grid);
        }

    return answer ;    
}


int main()
{
    int a=7 ;
    cout<<(a=4);
}








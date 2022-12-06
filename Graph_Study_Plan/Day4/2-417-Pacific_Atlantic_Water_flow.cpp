// https://leetcode.com/problems/pacific-atlantic-water-flow/









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


static int arr[] = {0,-1,0,1,0};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
{
    int n = heights.size();
    int m = heights[0].size();
    if(n==1 && m==1)
        return {{0,0}};

    vector<vector<bool>>visited_pacific(n,vector<bool>(m,false));
    vector<vector<bool>>visited_atlantic(n,vector<bool>(m,false));

    queue<pair<int,int>> q1 ;
    //pacific ocean
    for (int i = 0; i < n; i++)
    {
        visited_pacific[i][0] = true ;
        q1.push({i,0}) ;
    }
    for (int i = 0; i < m; i++)
    {
        visited_pacific[0][i] = true ;
        q1.push({0,i}) ;
    }
    while (!q1.empty())
    {
        int srcx = q1.front().first ;
        int srcy = q1.front().second ;
        q1.pop();
        for (short i = 0; i < 4; i++)
        {
            int newx = srcx+arr[i];
            int newy = srcy+arr[i+1];
            if(newx>=0 && newy>=0 && newx<n && newy<m && !visited_pacific[newx][newy] && heights[newx][newy]>=heights[srcx][srcy])
            {
                visited_pacific[newx][newy] = true ;
                q1.push({newx , newy});
            }
        }
    }
    






    //atlantic ocean 
    for (int i = 0; i < n; i++)
    {
        visited_atlantic[i][m-1] = true ;
        q1.push({i,m-1}) ;
    }
    for (int i = 0; i < m; i++)
    {
        visited_atlantic[n-1][i] = true ;
        q1.push({n-1,i}) ;
    }
    while (!q1.empty())
    {
        int srcx = q1.front().first ;
        int srcy = q1.front().second ;
        q1.pop();
        for (short i = 0; i < 4; i++)
        {
            int newx = srcx+arr[i];
            int newy = srcy+arr[i+1];
            if(newx>=0 && newy>=0 && newx<n && newy<m && !visited_atlantic[newx][newy] && heights[newx][newy]>=heights[srcx][srcy])
            {
                visited_atlantic[newx][newy] = true ;
                q1.push({newx , newy});
            }
        }
    }


    vector<vector<int>>ans1 ;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(visited_atlantic[i][j]&&visited_pacific[i][j])
                ans1.push_back({i,j});
    


    return ans1 ;

}
















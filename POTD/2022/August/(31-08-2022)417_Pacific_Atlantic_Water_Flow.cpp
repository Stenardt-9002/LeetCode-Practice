// https://leetcode.com/problems/pacific-atlantic-water-flow/






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void dfs_util(vector<vector<int>>heights , vector<vector<bool>> &visited , int srcx , int srcy ,int n ,int m)
{
    visited[srcx][srcy] = true ;

    if(srcx>=1 && !visited[srcx-1][srcy] && heights[srcx-1][srcy]>=heights[srcx][srcy]  )
        dfs_util(heights , visited , srcx-1 , srcy , n , m);
    
    if(srcx<n-1 && !visited[srcx+1][srcy] && heights[srcx+1][srcy]>=heights[srcx][srcy]  )
        dfs_util(heights , visited , srcx+1 , srcy , n , m);

    if(srcy>=1 && !visited[srcx][srcy-1] && heights[srcx][srcy-1]>=heights[srcx][srcy]  )
        dfs_util(heights , visited , srcx , srcy-1 , n , m);
    
    if(srcy<m-1 && !visited[srcx][srcy+1] && heights[srcx][srcy+1]>=heights[srcx][srcy]  )
        dfs_util(heights , visited , srcx , srcy+1 , n , m);


}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>> ans1 ;
        int n = heights.size()    ;
        int m = heights[0].size()    ;
        if(m==0 || n==0)
            return {} ;
        vector<vector<bool>> visisted_pac (n , vector<bool>(m,false));
        vector<vector<bool>> visisted_atl (n , vector<bool>(m,false));

        for (int i1 = 0; i1 < n; i1++)
        {
            dfs_util(heights , visisted_pac , i1 , 0, n,m);
            dfs_util(heights , visisted_atl , i1 , m-1,n,m);
        }

        for (int i1 = 0; i1 < m; i1++)
        {
            dfs_util(heights , visisted_pac ,  0 , i1,n,m);
            dfs_util(heights , visisted_atl ,  n-1 ,i1,n,m);
        }

        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                if(visisted_atl[i1][j1] && visisted_pac[i1][j1])
                    ans1.push_back({i1,j1});


        return ans1 ;

    }


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    int intup, intcol ;
    while (testcase--)
    {
        cin>>intup>>intcol ;
        vector<vector<int>> rental(intup , vector<int>(intcol));
        for (int i1 = 0; i1 < intup; i1++)
            for (int j1 = 0; j1 < intcol; j1++)
                cin>>rental[i1][j1];

        vector<vector<int>> zans1 = pacificAtlantic(rental) ;
        for (auto vec : zans1)
        {
            for(auto ele : vec)
                cout<<ele<<" ";
            cout<<endl ;
        }
        
        cout<<endl;

    }
    return 0 ;
}









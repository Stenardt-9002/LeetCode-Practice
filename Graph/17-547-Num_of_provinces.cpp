
// https://leetcode.com/problems/number-of-provinces/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

void dfs_util(vector<vector<int>>& isConnected,vector<bool>&visited,int src,int n) 
{
    if(!visited[src])
    {
        visited[src] = true ;
        for(int i1 = 0;i1<n;i1++)
            if(i1!=src && isConnected[src][i1]==1)
                dfs_util(isConnected,visited,i1,n);
    }
    return ;
}
int findCircleNum(vector<vector<int>>& isConnected) 
{
    int n = isConnected.size();
    int num_component = 0;
    vector<bool>visited(n,false);
    for (int i1 = 0; i1 < n; i1++)
        if(!visited[i1])    
        {
            dfs_util(isConnected,visited,i1,n);
            num_component++ ;
        }
            
    cout<<endl<<num_component;
    return num_component ;
}



int main(int argc, char const *argv[])
{
    int n ;cin>>n ;
    vector<vector<int>>ans1(n,vector<int>(n,0));
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            cin>>ans1[i1][j1];
    
    findCircleNum(ans1);
    return 0;
}




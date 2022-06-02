    // https://leetcode.com/problems/is-graph-bipartite/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



bool dfs_util(int src,int cur_col ,vector<int>&visited_c,vector<vector<int>>graph)
{
    if(visited_c[src]==-1)
        visited_c[src] = cur_col ;
    for(auto child:graph[src])
        if(visited_c[child]==-1)
        {
            if (dfs_util(child, 1 - cur_col, visited_c, graph))
                return true;
        }
        else if(visited_c[src]==visited_c[child])
            return true;
    return false ;
}


bool bfs_util(int src ,vector<int>&visited_c,vector<vector<int>>graph)
{
    queue<int> q1 ;
    q1.push(src);
    visited_c[src] = 0 ;
    while(!q1.empty())
    {
        int front = q1.front();
        q1.pop();
        //visit neighbours
        for(auto child : graph[front])
        {
            if(!visited_c[child]==-1)
            {
                visited_c[child] = 1-visited_c[front];
                q1.push(child);
            }
            else if(child!=front && visited_c[child]==visited_c[front])
            {
                cout<<"\nDEBUG"<<child<<" "<<front;
                return true;
            }
        }
    }
    return false ;
}









bool isBipartite(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int>visited_col(n,-1);
//    for(int i1=0;i1<n;i1++)
//        if(visited_col[i1]==-1)
//            if(dfs_util(i1,0,visited_col,graph))
//                return false ;
//
//    return true;


    for(int i1=0;i1<n;i1++)
        if(visited_col[i1]==-1)
            if(bfs_util(i1,visited_col,graph))
                return false ;

    return true;


}



int main() {
    
    int n ;
    cin>>n ;
    vector<int>temp1 ;
    int val,val2 ;
    vector<vector<int>>graph;
    for(int i1 = 0;i1<n;i1++)
    {
        cin>>val ;
        for(int k=0;k<val;k++)
        {
            cin>>val2 ;
            temp1.push_back(val2);
        }
        graph.push_back(temp1);
    }
    return 0;
}


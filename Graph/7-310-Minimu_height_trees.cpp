// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
{   
    if(n==0)
        return {} ;
    if(n==1)
        return {0} ;

    vector<int> *graph1 = new vector<int>[n];
    vector<int> in_degree(n,0) ;
    vector<int>ans1 ;
    for(auto x:edges)
    {
        in_degree[x[0]]++ ;
        in_degree[x[1]]++ ;
        graph1[x[0]].push_back(x[1]) ;
        graph1[x[1]].push_back(x[0]) ;
    }    

    queue<int> q1 ;
    for(int i1=0;i1<n;i1++)
        if(in_degree[i1]==1)
            q1.push(i1) ;


    while (!q1.empty())
    {
        ans1.clear();
        int qsize = q1.size() ;
        for(int i1 = 0 ; i1<qsize;i1++)
        {
            int src = q1.front();
            ans1.push_back(src) ;
            q1.pop() ;
            for(auto neig : graph1[src])
                if(--in_degree[neig]==1) //leaf
                    q1.push(neig);
                // in_degree[neig]--;
        }
    }
    

    delete []graph1 ;
    return ans1 ;
}





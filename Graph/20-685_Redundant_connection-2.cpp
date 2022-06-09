


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






int root(vector<int> &paremnt , int k)
{
  if(paremnt[k]!=k)
    paremnt[k] = root(paremnt,paremnt[k]) ;
  return paremnt[k];
}




vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
{
    int n = edges.size();
    vector<int> parent(n+1,0),posA,posB;

    for(auto &x: edges)
    {
        if(parent[x[1]]==0)
          parent[x[1]]=x[0];
        else
        {
          posA = {parent[x[1]],x[1] };
          posB = x ;
          x[1] = 0;
        }
    }

      //union find
    for(int i1 = 1 ; i1<=n ; i1++)
        parent[i1]=i1 ;


    for(auto &x: edges)
    {
        if(x[1]==0)
          continue ;

        int u = x[0] ;
        int v = x[1] ;
        int pu = root(parent,u);

        if(pu==v)
        {
          if(posA.empty())
            return x ;
          return posA ;
        }
        parent[v]=pu ;
    }
    return posB ;
}

// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






class Tuple {

public:
  int node,mask_val,dist ;
  Tuple (int nodes , int masks , int dists)
  {
    this->node = nodes ;
    this->mask_val = masks ;
    this->dist = dists ;
  }
};




int shortestPathLength(vector<vector<int>>& graph)
{
  int i1,n = graph.size();
  queue<Tuple> q1 ;

  set<pair<int,int>> vsisted_array ;
  int mask_val , final_ans = (1<<n)-1 ;

  for(i1=0;i1<n;i1++)
  {
    mask_val = (1<<i1) ;
    Tuple sa1(i1,mask_val,1);
    q1.push(sa1);
    vsisted_array.insert({i1,mask_val});
  }


  while (!q1.empty())
  {
    Tuple top1 = q1.front();
    q1.pop();
    if(top1.mask_val==final_ans)
      return top1.dist ;


    //visit neigbours
    for(auto neig: graph[top1.node])
    {
      int mixed_mask = top1.mask_val ;
      mixed_mask |= (1<<neig);

      Tuple sa1(neig,mixed_mask,top1.dist+1);

      if(vsisted_array.find({neig,mixed_mask})==vsisted_array.end())
      {
        vsisted_array.insert({neig,mixed_mask});
        q1.push(sa1);
      }
    }
  }
  return -1 ;

}

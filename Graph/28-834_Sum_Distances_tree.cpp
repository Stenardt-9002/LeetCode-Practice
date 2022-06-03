
// https://leetcode.com/problems/sum-of-distances-in-tree/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




void dfs_traversal1(int src , int parent , vector<int>&count_nodes , vector<int> &ans1 , vector<vector<int>> &graph1)
{
  // Postorder
  for (auto x : graph1[src] )
  {
    if(x==parent)
    continue;
    dfs_traversal1(x,src,count_nodes,ans1,graph1);
    count_nodes[src]+=count_nodes[x];
    ans1[src]+=(ans1[x]+count_nodes[x]);
  }
}

//getting answer
void dfs_traversal2(int src , int parent , vector<int>&count_nodes , vector<int> &ans1 , vector<vector<int>> &graph1,int n)
{
  // Preorder
  for (auto x : graph1[src] )
  {
    if(x==parent)
    continue;

    ans1[x]=(ans1[src]-count_nodes[x]+n-count_nodes[x]);
    dfs_traversal2(x,src,count_nodes,ans1,graph1,n);
  }

}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
{
  vector<vector<int>> graph1(n);
  for (auto x : edges)
  {
    graph1[x[0]].push_back(x[1]);
    graph1[x[1]].push_back(x[0]);
  }

    vector<int>count_nodes(n,1);//subtrees nodes count
    vector<int>ans1(n,0);//sum of all distances
    int src = 0;
    dfs_traversal1(src,-1,count_nodes,ans1,graph1);
    for (auto x : ans1 )
      cout<<" "<<x;
      cout<<endl;
    for (auto x : count_nodes )
      cout<<" "<<x;
      cout<<endl;
    dfs_traversal2(src,-1,count_nodes,ans1,graph1,n);
    return ans1 ;
}



int main(int argc, char const *argv[])
{
  int  n ;
  cin>>n ;
  int val1,val2 ;
  vector<vector<int>> edges;
  for (int i1 = 0; i1 < n; i1++)
  {
    cin>>val1>>val2;
    edges.push_back({val1,val2});
  }
  cin>>n;
  vector<int> ans1 = sumOfDistancesInTree(n,edges);
  // for (auto x : ans1 )
  //   cout<<" "<<x;


  return 0;
}

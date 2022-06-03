// https://leetcode.com/problems/keys-and-rooms/submissions/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




void dfs_top_util(int src , stack<int>&s1 , vector<bool>&visited , vector<vector<int>>&graph1)
{
  visited[src] = true;
  for(auto x = graph1[src].begin() ; x!=graph1[src].end() ; x++)
    if(!visited[*x])
      dfs_top_util(*x,s1,visited,graph1);

  s1.push(src);
}



bool canVisitAllRooms(vector<vector<int>>& rooms)
{
  int i1,n = rooms.size();
  stack<int> s1;
  vector<bool>vsitied(n,false);
  dfs_top_util(0,s1,vsitied,rooms);
  for(i1=0;i1<n;i1++)
    if(!vsitied[i1])
      return false ;

  return (s1.size()==n);
}




int main(int argc, char const *argv[])
{
  int  n ;
  cin>>n ;
  int val1,val2 ;

  vector<vector<int>> graph1;
  for (int i1 = 0; i1 < n; i1++)
  {
    vector<int>temp1;
    cin>>val1 ;
    for(int k=0;k<val1;k++)
    {
        cin>>val2;
        temp1.push_back(val2);
    }
    graph1.push_back(temp1);
  }

  cout<<" "<<canVisitAllRooms(graph1);
  // for (auto x : ans1 )
  //   cout<<" "<<x;


  return 0;
}

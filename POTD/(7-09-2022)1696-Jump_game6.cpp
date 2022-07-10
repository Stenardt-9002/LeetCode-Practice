// https://leetcode.com/problems/jump-game-vi/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int func_recur(int cur ,int k , vector<int> nums , vector<int>&dp1)
{
  if(cur<=0)
    return 0 ;
  if(dp1[cur]!=-1)
    return dp1[cur] ;
  int ans1 = INT_MIN ;
  int i1 = 0 ;
  while(i1++<k && cur-i1>=0)
    ans1 = max(ans1 , func_recur(cur-i1,k,nums,dp1)+nums[cur-i1] );

  dp1[cur] = ans1 ;
  return ans1 ;
}

// 
// int maxResult(vector<int>& nums, int k)
// {
//   int n = nums.size();
//   std::vector<int> dp1(n,-1);
//
//   dp1[0] = 0;
//   for (int i1 = 0; i1 < n; i1++)
//   {
//
//
//   }
//
//
//   return func_recur(n-1,k,nums,dp1)+nums[n-1];
// }

int main(int argc, char const *argv[])
{
    int n ,k ;
    cin>>n>>k;
    std::vector<int> v1(n);
    for(int i1 = 0;i1<n;i1++)
      cin>>v1[i1];


      cout<<endl<<maxResult(v1,k);
  return 0;
}

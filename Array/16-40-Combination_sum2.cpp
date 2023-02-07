
// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



void recursive_util(int ind , int target , vector<int> candy , vector<int> &ds ,vector<vector<int>> &ans1)
{
  if(ind==candy.size())
  {
    if(target==0)
      ans1.push_back(ds);
    return ;
  }


  if(target>=candy[ind])
  {
    ds.push_back(candy[ind]);
    recursive_util(ind+1,target-candy[ind],candy,ds,ans1);
    ds.pop_back();
  }
  recursive_util(ind+1,target,candy,ds,ans1);
}


// vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
// {
//   int n = A.size();
//   vector<vector<int>> ans1 ;
//   vector<int> s1 ;
//   sort(A.begin(),A.end());
//   A.erase(unique(A.begin(),A.end()),A.end() );
//   recursive_util(0 , B , A , s1 , ans1) ; //index , target , array , stack , list of list
//   return ans1 ;
// }

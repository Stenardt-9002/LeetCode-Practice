

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef  long long ll1d;



vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
  // int n = candidates.size();
  vector<vector<int>> ans1 ;
  vector<int> s1 ;
  // sort(candidates.begin(),candidates.end());
  // candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end() );
  recursive_util(0 , target , candidates , s1 , ans1) ; //index , target , array , stack , list of list

  return ans1 ;
}



void recursive_util(int cur_id , int taget ,vector<int> array ,  vector<int>&s1 , vector<vector<int>> &ans1 )
{
  if(cur_id==array.size())
  {
    if(taget==0)
      ans1.push_back(s1);
      // ans1.insert(s1);
    return  ;
  }

  if(array[cur_id]<=taget)
  {
    s1.push_back(array[cur_id]);
    recursive_util(cur_id , taget-array[cur_id] , array , s1 , ans1);
    s1.pop_back();
  }
  //not included
  recursive_util(cur_id+1 , taget , array , s1 , ans1);
}


vector<vector<int> > combinationSum(vector<int> &A, int B)
{
  int n = A.size();
  vector<vector<int>> ans1 ;
  vector<int> s1 ;
  sort(A.begin(),A.end());
  A.erase(unique(A.begin(),A.end()),A.end() );
  recursive_util(0 , B , A , s1 , ans1) ; //index , target , array , stack , list of list

  return ans1 ;
}

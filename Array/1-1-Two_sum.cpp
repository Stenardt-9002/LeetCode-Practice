// https://leetcode.com/problems/two-sum/submissions/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


class Dat_struct
{
  public :
  int data , index ;
};

bool comp1(Dat_struct a1 , Dat_struct a2)
{
  return a1.data<a2.data ;
}



vector<int> twoSum(vector<int>& nums, int target)
{
  int i1 = 0,n = nums.size(),j1;
  Dat_struct *arra = new Dat_struct[n];
  for(i1=0;i1<n;i1++)
    arra[i1].data = nums[i1],arra[i1].index = i1;


  // sort(nums.begin(),nums.end());
  sort(arra,arra+n , comp1 );

  // for(i1=0;i1<n;i1++)
  //   cout<<" "<<arra[i1].data ;
  // cout<<endl ;
  // for(i1=0;i1<n;i1++)
  //   cout<<" "<<arra[i1].index ;
  // cout<<endl ;
  // return {};
  i1 = 0,j1 = n-1;
  while(i1<j1)
  {
      if(arra[i1].data+arra[j1].data<target)
        i1++ ;
      else if(arra[i1].data+arra[j1].data>target)
        j1--;
      else
        return {arra[i1].index,arra[j1].index};
  }

  return {arra[i1].index,arra[j1].index};
}



int main(int argc, char const *argv[])
{
  std::vector<int> v = {3,2,4};
  int targetn = 6  ;
  auto x = twoSum(v,targetn);
  for (auto y : x )
    cout<<" "<<y;
  cout<<endl;
  return 0;
}

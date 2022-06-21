// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


vector<vector<int>> threeSum(vector<int>& nums)
{
  vector<vector<int>> s1 ;
  int n = nums.size(),target1,i1=0;
  sort(nums.begin(),nums.end());
  int fptr , bptr ;
  for (i1 = 0; i1 < n ; i1++)
  {
    target1 = -nums[i1] ;
    fptr = i1+ 1; bptr = n-1 ;
    while (fptr<bptr)
    {
        int cur_sum = nums[bptr]+nums[fptr];
        if(cur_sum<target1) fptr++ ;
        else if(cur_sum>target1)bptr-- ;
        else
        {
          std::vector<int> temp_trip = {nums[i1] , nums[fptr] , nums[bptr]  };
          s1.push_back(temp_trip);

          while(fptr<bptr && nums[fptr]==temp_trip[1] )fptr++ ;
          while(fptr<bptr && nums[bptr]==temp_trip[2] )bptr-- ;
        }
    }
    while(i1+1<n && nums[i1+1]==nums[i1] )
      i1++ ;//duplicate values removal
  }
  return s1 ;
}

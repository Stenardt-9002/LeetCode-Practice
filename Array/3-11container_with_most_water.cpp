
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



int maxArea(vector<int>& height)
{

  int n = height.size() ,i1=0 ,j1 = n-1;
  int h  ,water = INT_MIN ;
  while(i1<j1)
  {
    h = min(height[i1],height[j1]) ;
    water = max(water , h*(j1-i1));
    while(height[i1]<=h && i1<j1 ) i1++ ;
    while(height[j1]<=h && i1<j1 ) j1-- ;
  }
  return water ;
}

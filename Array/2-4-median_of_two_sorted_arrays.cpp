// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


double single_med(std::vector<int> v,int n)
{
  if(n==0)
    return -1 ;
  if(n%2==0)
    return (double)(v[n/2]+v[n/2 -1])/2.0;
}


double fuc3(int a, int b , int c)
{
  return a+b+c-max({a,b,c})-min({a,b,c});
}

double fuc4(int a , int b , int c ,int d)
{
  return ((a+b+c+d)-max({a,b,c,d})-min({a,b,c,d}))/2.0;
}

double base_case_handler(std::vector<int> nums1 , std::vector<int> nums2 , int n , int m)
{
  if(n==0)
    return single_med(nums2,m);

  else if(n==1)
  {
    if(m==1)
      return (double)(nums1[0]+nums2[0])/2.0;

    if(m%2==1)
      return (double)(nums2[m/2]+fuc3(nums1[0],nums2[m/2 -1],nums2[m/2 -1]))/2.0;

    return fuc3(nums2[m/2],nums2[m/2 -1],nums1[0]);
  }

  else if(n==2)
  {
    if(m==2)
      return fuc4(nums1[0],nums2[1],nums2[0],nums2[1]);


    if(m%2==1)
      return (double)(nums2[m/2]+fuc3(nums1[0],nums2[m/2 -1],nums2[m/2 -1]))/2.0;

    return fuc3(nums2[m/2],nums2[m/2 -1],nums1[0]);

  }
}

double findMed_Util(std::vector<int> nums1 , std::vector<int> nums2 , int n , int m)
{
  // nums1 , small
  if(n<3)
    return base_case_handler(nums1.nums2,n,m);
  int idxA = (N-1)/2; idxB = (M-1)/2 ;
  if(nums1[idxA]<=nums2[idxB])
    return findMed_Util(nums1.begin()+idxA,nums2,n/2 +1,m-idxA);

  return findMed_Util(nums1,nums2+idxA,n/2 +1,m-idxA);
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
  int n = nums1.size();int m = nums2.size();
  if(n>m)
    return findMed_Util(nums2,nums1,m,n);

    return findMed_Util(nums1,nums2,n,m);
}

// https://leetcode.com/problems/trapping-rain-water/






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;



    int trap(vector<int>& height) 
    {
         int n= height.size();
          int left = 0 , right = n-1 ;
          int res = 0 ;
          int maxleft = 0 , maxright = 0 ;

          while (left<=right)
          {
            if(height[left]<=height[right])
            {
              if(height[left]>=maxleft )
                maxleft = height[left];
              else
                res+=maxleft-height[left];

              left++ ;
            }

            else
            {
              if(height[right]>=maxright)
                maxright = height[right];
              else
                res+=maxright-height[right];

              right-- ;
            }

          }
          return res ;
    }


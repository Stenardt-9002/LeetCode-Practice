// https://leetcode.com/problems/maximum-length-of-repeated-subarray/




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

// int largest_array(vector<int> nums1 , vector<int> nums2 , int startind1 , int startind2)
// {
//     int smae = 0 ;
//     int n1 = nums1.size();
//     int n2 = nums2.size();
//     while(startind1<n1 && startind2<n2 && nums1[startind1]==nums2[startind2])
//     {
//         smae++ ;
//         startind1++ ;
//         startind2++ ;
//     }
//     return smae ;
// }

// int findLength(vector<int>& nums1, vector<int>& nums2) 
// {
//     vector<vector<int>> hash_second_array(102) ;
//     int n = nums2.size();
//     for (int i1 = 0; i1 < n; i1++)
//         hash_second_array[nums2[i1]].push_back(i1);

//     n = nums1.size();
//     int ans1 = 0 ;
//     for (int i1 = 0; i1 < n; i1++)
//         {
//             if(hash_second_array[nums1[i1]].size()!=0)
//                 for (auto ind : hash_second_array[nums1[i1]])
//                     ans1 = max(ans1 , largest_array(nums1,nums2 , i1 , ind));

//             if(ans1>n-i1)
//                 break ;
//         }
    
//     return ans1 ;

// }

int findLength(vector<int>& nums1, vector<int>& nums2) 
{
    if(nums1.size()<nums2.size())
        swap(nums1,nums2);

    int n = nums1.size();
    int m = nums2.size();
    vector<int> dp1(m+1 , 0);

    int ans1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = m-1; j1 >=0; --j1)
        {
            if(nums1[i1]==nums2[j1])
                dp1[j1+1] = 1+dp1[j1];
            else 
                dp1[j1+1] = 0 ;

            ans1 = max(ans1 , dp1[j1+1]);
        }
        
    
    return ans1 ;
}

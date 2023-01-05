// https://leetcode.com/problems/continuous-subarray-sum/






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




bool checkSubarraySum(vector<int>& nums, int k) 
{
    int n = nums.size();
    if(n<2)
        return false ;

    unordered_map<int,int> map1 ;
    map1[0] = -1;
    int contguous_sum = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        contguous_sum+=nums[i1];
        if(k!=0)
            contguous_sum%=k ;

        if(map1.find(contguous_sum)!=map1.end())
        {
            if(i1-map1[contguous_sum]>1)//atleast 2
                return true ;
        }
        else 
            map1[contguous_sum] = i1 ;

    }
    return false ;
}


// bool checkSubarraySum(vector<int>& nums, int k) 
// {
//     int n = nums.size();
//     if(n<2)
//         return false ;

//     vector<int> map1(2*n+1,-1) ;
//     int contguous_sum = 0 ;
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         contguous_sum+=nums[i1];
//         if(k!=0)
//             contguous_sum%=k ;

//         if(map1[contguous_sum+n]!=-1)
//         {
//             if(i1-map1[contguous_sum+k]>1)//atleast 2
//                 return true ;
//         }
//         else 
//             map1[contguous_sum+n] = i1 ;

//     }
//     return false ;
// }











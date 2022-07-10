#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




// int maximumsSplicedArray(vector<int> &nums1 , vector<int> &nums2)
// {
//     int n1 = nums1.size();
//     long long int sum1 = 0,sum2 = 0;
//     for (int i1 = 0; i1 < n1; i1++)
//         sum1+=nums1[i1] ,sum2+=nums2[i1]   ;

//     if(sum2>sum1)
//         {
//             nums1.swap(nums2);
//             sum1 = sum2 ;
//         }

//     vector<vector<long long int>>subaray_sum1(n1,vector<long long int>(n1,0));
//     vector<vector<long long int>>subaray_sum2(n1,vector<long long int>(n1,0));
//     vector<vector<long long int>>diff_subaray_sum(n1,vector<long long int>(n1,0));
//     for (int i1 = 0; i1 < n1; i1++)
//     {
//         subaray_sum1[i1][i1] = nums1[i1];
//         for (int j1 = i1+1; j1 < n1; j1++)
//         {
//             subaray_sum1[i1][j1] = subaray_sum1[i1][j1-1]+nums1[j1];
//         }
//     }
//     for (int i1 = 0; i1 < n1; i1++)
//     {
//         subaray_sum2[i1][i1] = nums2[i1];
//         for (int j1 = i1+1; j1 < n1; j1++)
//         {
//             subaray_sum2[i1][j1] = subaray_sum2[i1][j1-1]+nums2[j1];
//         }
//     }

//     // cout<<endl;
//     long long intmin = INT_MAX;
//     for (int i1 = 0; i1 < n1; i1++)
//     {
//         // cout<<endl ;
//         for (int j1 = i1; j1 < n1; j1++)
//             intmin = min(intmin , subaray_sum1[i1][j1]-subaray_sum2[i1][j1]) ;//,cout<<" "<<subaray_sum1[i1][j1] ;
//     }
//     //     for (int i1 = 0; i1 < n1; i1++)
//     // {
//     //     cout<<endl ;
//     //     for (int j1 = 0; j1 < n1; j1++)
//     //         cout<<" "<<subaray_sum2[i1][j1] ;
//     // }
//     if(intmin<0)
//         sum1-=intmin;

//     return sum1 ;


// }

int maximumsSplicedArray(vector<int> &nums1 , vector<int> &nums2)
{
    int n1 = nums1.size();
    long long int sum1 = 0,sum2 = 0;
    for (int i1 = 0; i1 < n1; i1++)
        sum1+=nums1[i1] ,sum2+=nums2[i1]   ;

    if(sum2>sum1)
        {
            nums1.swap(nums2);
            sum1 = sum2 ;
        }

    vector<vector<int>>diff_subaray_sum(n1,vector<int>(n1,0));


    for (int i1 = 0; i1 < n1; i1++)
    {
        diff_subaray_sum[i1][i1] = nums1[i1]-nums2[i1];
        for (int j1 = i1+1; j1 < n1; j1++)
        {
            diff_subaray_sum[i1][j1] = diff_subaray_sum[i1][j1-1]+nums1[j1]-nums2[j1];
        }
    }

    // cout<<endl;
    int intmin = INT_MAX;
    for (int i1 = 0; i1 < n1; i1++)
    {
        for (int j1 = i1; j1 < n1; j1++)
            intmin = min(intmin ,diff_subaray_sum[i1][j1]) ;
    }
    //     for (int i1 = 0; i1 < n1; i1++)
    // {
    //     cout<<endl ;
    //     for (int j1 = 0; j1 < n1; j1++)
    //         cout<<" "<<subaray_sum2[i1][j1] ;
    // }
    if(intmin<0)
        sum1-=intmin;

    return sum1 ;


}

int main(int argc, char const *argv[])
{

    // vector<int > nums1 = {50,20,50,40,20};
    // vector<int > nums2 = {20,40,20,70,30};

    vector<int > nums1 = {10,20,50,15,30,10};
    vector<int > nums2 = {40,20,10,100,10,10};
    cout<<"\nFUCJK"<<maximumsSplicedArray(nums1,nums2);
    return 0;
}



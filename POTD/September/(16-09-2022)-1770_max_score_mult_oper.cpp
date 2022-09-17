// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


// int maximumScore(vector<int>& nums, vector<int>& multipliers) 
// {
//     multiset<int> s1(nums.begin(),nums.end())    ;
//     sort(multipliers.begin(),multipliers.end());
//     int ans1 = 0;
//     int i1;
//     for (i1 = multipliers.size()-1; i1 >=0 && multipliers[i1]>=0; i1--)
//         if(multipliers[i1]>=0)
//         {
//             int cur_max = *(s1.rbegin());
//             ans1+=(cur_max*multipliers[i1]);
//             s1.erase(*(s1.rbegin()));
//         }    
    
    
//     int j1 = 0;
//     for ( j1 = 0; j1 <=i1; j1++)
//     {
//         int min_ele = *(--s1.rend())    ;
//         ans1+=(min_ele*multipliers[j1]);
//         s1.erase(*(--s1.rend()));
//     }
//     return ans1 ;
    
// }





// int maximumScore(vector<int>& nums, vector<int>& multipliers) 
// {
//     multiset<int> s1(nums.begin(),nums.end())    ;
//     sort(multipliers.begin(),multipliers.end());
//     multiset<int> negativenums , positivenums ;

//     int ans1 = 0;
//     int i1;
//     for(auto ele : s1)
//         if(ele>=0)
//             positivenums.insert(ele) ;
//         else 
//             negativenums.insert(ele);
    
    
    
//     for (i1 = multipliers.size()-1; i1 >=0 && multipliers[i1]>=0; i1--)
//         if(multipliers[i1]>=0)
//         {
//             if(!positivenums.empty())
//             {
//                 int cur_max = *(positivenums.rbegin());
//                 ans1+=(cur_max*multipliers[i1]);
//                 positivenums.erase(*(positivenums.rbegin()));
//             }
//             else 
//             {
//                 int min_ele = *(negativenums.rbegin())    ;
//                 ans1+=(min_ele*multipliers[i1]);
//                 negativenums.erase(*(negativenums.rbegin()));
//             }
//         }  
//     int j1 = 0;
//     for ( j1 = 0; j1 <=i1; j1++)  
//     {
//         if(!negativenums.empty())
//         {
//             int min_ele = *(--negativenums.rend());
//             ans1+=(min_ele*multipliers[j1]);
//             negativenums.erase(*(--negativenums.rend()));
//         }
//         else 
//         {
//             int min_ele = *(--positivenums.rend())    ;
//             ans1+=(min_ele*multipliers[j1]);
//             positivenums.erase(*(--positivenums.rend()));
//         }
//     }
//     // int j1 = 0;
//     // for ( j1 = 0; j1 <=i1; j1++)
//     // {
//     //     int min_ele = *(--s1.rend())    ;
//     //     ans1+=(min_ele*multipliers[j1]);
//     //     s1.erase(*(--s1.rend()));
//     // }
//     return ans1 ;
    
// }



int recurive_func(int start , int k , int n , int m,vector<int>nums , vector<int>multipliers ,vector<vector<int>>&dp1)
{
    if(k==m)
        return 0 ;
    
    if(dp1[start][k]!=-1)
        return dp1[start][k];

    int pickleft = recurive_func(start+1 , k+1 , n,m,nums , multipliers , dp1)+(nums[start]*multipliers[k]);
    int picknotleft = recurive_func(start , k+1 , n,m,nums , multipliers , dp1)+(nums[n-k+start-1]*multipliers[k]);
    //since elemetsn are n>=m then we dont have to maintain indices for nums only multiplers required


    return dp1[start][k] = max(pickleft,picknotleft);

}



// int maximumScore(vector<int>& nums, vector<int>& multipliers) 
// {
//     vector<vector<int>>dp1(1001,vector<int>(1001,-1));
//     int n = nums.size();
//     int m = multipliers.size();
//     // assert n>=m ;
    
//     return recurive_func(0 , 0 ,n,m, nums , multipliers ,dp1);

// }



int maximumScore(vector<int>& nums, vector<int>& multipliers) 
{
    int n = nums.size();
    int m = multipliers.size();
    // assert n>=m ;
    vector<vector<int>>dp1(m+1,vector<int>(m+1,0));

    for (int start = m-1; start >=0; start--)
    {
        for (int len1 = m-1; len1 >=0; len1--)
        {
            int right = n-1-(len1-start);
            if(right<0 || right>=n)
                continue ; 
            int leftpick = dp1[start+1][len1+1]+(nums[start]*multipliers[len1]);
            int rightpick = dp1[start][len1+1]+(nums[right]*multipliers[len1]);
            dp1[start][len1] = max(leftpick , rightpick);

        }
        
    }
    
    
    return dp1[0][0];

}




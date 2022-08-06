
// https://leetcode.com/problems/combination-sum-iv/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int recusion_util(vector<int> nums,int target)
{
    if(target==0)
        return 1; 

    int n = nums.size();

    int res = 0 ;
    for (int i1 = 0; i1 < n; i1++)
        if(target>=nums[i1])
            res+=recusion_util(nums,target-nums[i1]);
        
    return res ;
}



// int combinationSum4(vector<int>& nums, int target) 
// {
//     if(nums.size()==0)
//         return 0 ;

//    return  recusion_util( nums , target);

// }

//DP solution not usable if  target is very large
// int combinationSum4(vector<int>& nums, int target) 
// {
//     if(nums.size()==0 && target==0)
//         return 1 ;

//     if(nums.size()==0)
//         return 0 ;

//     vector<long long int > combinartion(target+1,0);
//     combinartion[0] = 1;
//     for (int i1 = 1; i1 < target+1; i1++)
//         for (int j1 = 0; j1 < nums.size(); j1++)
//             if(i1-nums[j1]>=0)
//                 combinartion[i1]+=combinartion[i1-nums[j1]];

//     return combinartion[target];
   

// }




int dfs_new_recursion(vector<int> nums , int target , map<int,int> &m1 )
{
    if (target<0)
        return 0 ;
    if(target==0)
        return 1 ;
    
    if(m1.find(target)!=m1.end())
        return m1[target];

    int res = 0 ;
    for (int i1 = 0; i1 < nums.size(); i1++)
    {
        int count_dfs = dfs_new_recursion(nums,target-nums[i1],m1);
        if(target>=nums[i1])
            m1[target-nums[i1]] = count_dfs ;
        
        res+=count_dfs ;
    }
    return res ;

}


int combinationSum4(vector<int>& nums, int target) 
{
    if(nums.size()==0 && target==0)
        return 1 ;

    if(nums.size()==0)
        return 0 ;

    map<int,int> m1 ;
    return dfs_new_recursion(nums,target , m1);

}






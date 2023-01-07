// https://leetcode.com/contest/weekly-contest-318/problems/maximum-sum-of-distinct-subarrays-with-length-k/








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



long long maximumSubarraySum(vector<int>& nums, int k) 
{
    ll ans1 = 0,i1=0 ;
    ll n = nums.size();
    ll cur_sum = 0;
    set<ll>current_set ;
    for (i1 = 0;i1 < k; i1++)
    {
        current_set.insert(nums[i1]);
        cur_sum+=nums[i1];
    }
    if(current_set.size()!=k)
        cur_sum = 0 ;
    
    ans1 = max(ans1 , cur_sum);
    for (i1 = k; i1 < n; i1++)
    {
        current_set.erase(nums[i1-k]);
        current_set.insert(nums[i1]);
        if(cur_sum==0)
        {
            if(current_set.size()==k)
            {
                for(auto data : current_set)
                    cur_sum+=data ;
            }
        }
        else if(current_set.size()==k)
        {
            cur_sum-=nums[i1-k];
            cur_sum+=nums[i1];
        }
        ans1 = max(ans1 , cur_sum);
    }
    
    return ans1 ;

}

long long maximumSubarraySum(vector<int>& nums, int k) 
{
    ll ans1 = 0,i1=0 ;
    ll n = nums.size();
    ll cur_sum = 0;
    deque<ll>q1 ;
    set<ll> s1 ;
    
    for (i1 = 0;i1 < k; i1++)
    {
        s1.insert(nums[i1]);
        q1.push_back(nums[i1]);
        cur_sum+=nums[i1];
    }
    
    if(s1.size()==k)
        ans1 = max(ans1 , cur_sum);
    for (i1 = k; i1 < n; i1++)
    {
        q1.pop_front();
        q1.push_back(nums[i1]);
        // s1.erase(nums[i1-k]);
        // s1.insert(nums[i1]);
        set<int> s1 ;
        for(auto var : q1)
            s1.insert(var);
        cur_sum+=nums[i1];
        cur_sum-=nums[i1-k];

        if(s1.size()==k)
        ans1 = max(ans1 , cur_sum);
    }
    
    return ans1 ;

}

long long maximumSubarraySum(vector<int>& nums, int k) 
{
    ll ans1 = 0,i1=0 ;
    ll n = nums.size();
    ll cur_sum = 0;
    unordered_map<ll,ll> map1 ;
    ll distinct_ele = 0 ;
    for (i1 = 0;i1 < k; i1++)
    {
        if(map1[nums[i1]]++==0)
            distinct_ele++ ;
        cur_sum+=nums[i1];
    }
    
    if(distinct_ele==k)
        ans1 = max(ans1 , cur_sum);
    for (i1 = k; i1 < n; i1++)
    {
        if(--map1[nums[i1-k]]==0)
            distinct_ele-- ;
        if(map1[nums[i1]]++==0)
            distinct_ele++ ;
        cur_sum+=nums[i1];
        cur_sum-=nums[i1-k];

        if(distinct_ele==k)
        ans1 = max(ans1 , cur_sum);
    }
    
    return ans1 ;

}
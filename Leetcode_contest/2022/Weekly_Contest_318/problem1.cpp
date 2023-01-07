// https://practice.geeksforgeeks.org/problems/sequence-fun5018/1





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

vector<int> applyOperations(vector<int>& nums) 
{
    vector<int> ans1 ;
    for (int i1 = 0; i1 < nums.size(); i1++)
    {
            if(i1<nums.size()-1 && nums[i1]==nums[i1+1] )
            {
                ans1.push_back(2*nums[i1]);
                ans1.push_back(0);

                i1++ ;
            }
            else 
                ans1.push_back(nums[i1]);
    }
    vector<int> ans2 ;
    for(auto var:ans1)
        if(var!=0)
            ans2.push_back(var);

    while (ans2.size()<nums.size())
        ans2.push_back(0);
    
    return ans2 ;
}
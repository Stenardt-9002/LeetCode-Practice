// https://leetcode.com/problems/set-mismatch/





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



vector<int> findErrorNums(vector<int>& nums) 
{
    int ans1 = 0 , ans2 = 0;
    int n = nums.size();
    int bit_set_pos ;
    int xor1 = nums[0];
    for (int i1 = 1; i1 < n; i1++)
        xor1=xor1^nums[i1];
    
    for (int i1 = 1; i1 <= n; i1++)
        xor1=xor1^i1;
    
    bit_set_pos = xor1&~(xor1-1);


    for (int i1 = 0; i1 < n; i1++)
        if(nums[i1]&bit_set_pos)
            ans1^=nums[i1];
        else 
            ans2^=nums[i1];

    for (int i1 = 1; i1 <=n; i1++)
        if(i1&bit_set_pos)
            ans1^=i1;
        else 
            ans2^=i1;
    bool found_flag = false  ;
    for(int i1 = 0 ; i1< n ;++i1)
        if(nums[i1]==ans1)
            found_flag = true ;

    //occurs twice and missing once
    if(found_flag)
        return {ans1,ans2};
    return {ans2 ,ans1};

}












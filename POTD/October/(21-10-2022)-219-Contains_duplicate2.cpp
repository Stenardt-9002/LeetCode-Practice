// https://leetcode.com/problems/contains-duplicate-ii/




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


bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    
    
    int n = nums.size();
    if(n==1)
        return false ;
    k = min(k+1,n);
    unordered_map<int,int> map1 ;
    for (int i1 = 0; i1 < k; i1++)
        if(map1[nums[i1]]++)
            return true ;

    for (int i1 = k; i1 < n; i1++)
    {
        map1[nums[i1-k]]--;
        if(map1[nums[i1]]++)
            return true ;
    }

    return false ;
}








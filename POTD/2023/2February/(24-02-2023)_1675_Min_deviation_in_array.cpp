// https://leetcode.com/problems/minimize-deviation-in-array/















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
















class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        int ans = INT_MAX ;
        multiset<int> s1 ; 
        for(auto num:nums)
            if(num%2)
                s1.insert(num*2);
            else 
                s1.insert(num);

        
        while (*(--s1.end())%2==0)
        {
            ans = min(ans , *(s1.rbegin())- *(s1.begin()));
            s1.insert(*(s1.rbegin())/2);
            s1.erase(--s1.end());
        }
        return min(ans , *(s1.rbegin())- *(s1.begin()));
    }
};  
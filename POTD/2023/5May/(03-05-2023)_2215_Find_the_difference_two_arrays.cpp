// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/











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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> coun1  , coun2 ;
        set<int> first(nums1.begin(),nums1.end()) ,second(nums2.begin(),nums2.end()) ;
        for(auto c: first)
            if(second.find(c)==second.end())
                coun1.push_back(c) ;
        for(auto c: second)
            if(first.find(c)==first.end())
                coun2.push_back(c) ;
        return {coun1 ,coun2 };
    }
};
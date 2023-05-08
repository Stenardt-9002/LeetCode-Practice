// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/









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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool>ans ; 
        int n = candies.size()    ;
        int max_value = *max_element(candies.begin() , candies.end());
        for(int i = 0 ; i<n ; i++)
            ans.push_back((candies[i]+extraCandies)>=max_value);
        return ans ; 
    }
};

// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/











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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> ans ; 
        sort(potions.begin(),potions.end())    ;
        int n = spells.size();
        int m = potions.size();
        for(int i = 0 ; i<n;++i)
        {
            long long int pos = (long long int)(ceil(((double)(success))/spells[i] ));
            ans.push_back(potions.end()-lower_bound(potions.begin(),potions.end(),pos ));
        }
        return ans ;
    }
};
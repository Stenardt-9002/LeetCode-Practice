// https://leetcode.com/problems/remove-stones-to-minimize-the-total/















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
    int minStoneSum(vector<int>& piles, int k) 
    {
        long long int sum2 = 0 ;
        for(auto x : piles)
            sum2+=x ;
        multiset<int> s1(piles.begin() , piles.end()) ;    
        int sum1 = 0 ;
        for (int i = 0; i < k; i++)
        {
            int val = *(--s1.end());
            s1.erase(s1.find(val));
            int new_val = val-val/2;
            sum1+=(val/2);
            s1.insert(new_val);
        }
        return sum2-sum1;

    }
};
























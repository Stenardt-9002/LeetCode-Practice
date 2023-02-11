// https://leetcode.com/problems/fruit-into-baskets/











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
    int totalFruit(vector<int>& fruits) 
    {
        int ans = 0;
        int n = fruits.size();
        int unique_ele = 0 ;
        vector<int> s1(n+1,0);
        int first_index = 0 ;
        for (int i = 0; i < n; i++)
        {
            if(s1[fruits[i]]++==0)
                unique_ele++ ;

            while (unique_ele>2)
                if(s1[fruits[first_index++]]--==1) 
                    unique_ele-- ;

            ans = max(i-first_index+1 , ans);
        }
        return ans ;

    }
};






















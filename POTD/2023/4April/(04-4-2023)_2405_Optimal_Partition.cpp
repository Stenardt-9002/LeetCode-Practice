// https://leetcode.com/problems/optimal-partition-of-string/









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
    int partitionString(string s) {
       int i = 0 , ans = 1 , bits = 0 ;
       int n = s.size();
        while(i<n) 
        {
            int val = s[i]-'a';
            if(bits&(1<<val))
            {
                bits = 0 ;
                ans++ ; 
            }
            bits |= (1<<val);
            i++ ;
        }   
        return ans ;
    }
};
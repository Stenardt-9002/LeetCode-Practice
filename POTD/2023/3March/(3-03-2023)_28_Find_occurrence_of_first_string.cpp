
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/







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
    int strStr(string haystack, string needle) {
        int found = haystack.find(needle);
            
        if(found != string::npos) 
        return found ;
        
        return -1 ;
    }
};







// https://leetcode.com/problems/greatest-common-divisor-of-strings/








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
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2==str2+str1)   
            return str1.substr(0,__gcd(str1.length() ,str2.length()));
        
        return "";
    }
};
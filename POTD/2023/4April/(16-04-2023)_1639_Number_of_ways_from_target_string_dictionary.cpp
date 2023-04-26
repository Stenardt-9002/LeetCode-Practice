// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/









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
    int numWays(vector<string>& words, string target) {
        int n = target.length();
        int mod = 1e9+7 ;
        vector<long long int> ans(n+1,0);
        ans[0] = 1;
        for(int i = 0 ; i<words[0].length();++i)
        {
            vector<int> hash_c(26);
            for(auto& w: words)
                hash_c[w[i]-'a']++ ;
            for(int j = n-1 ; j>=0 ;--j)
                ans[j+1] += (ans[j]*hash_c[target[j]-'a'])%mod ;
        }
        return ans[n]%mod ;
    }
};








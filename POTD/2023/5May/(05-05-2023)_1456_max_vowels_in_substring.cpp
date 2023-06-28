// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/






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












class Solution 
{
public:
    int maxVowels(string s, int k) 
    {
        int n = s.length();
        vector<int>hash(26,0)    ;
        int ans = 0; 
        for(int i = 0 ; i< k; i++)
            hash[s[i]-'a']++;
                
        ans = max(ans , hash['a'-'a']+hash['e'-'a']+hash['i'-'a']+hash['o'-'a']+hash['u'-'a']);
        for(int i = k ; i< n; i++)
        {
            hash[s[i-k]-'a']--;
            hash[s[i]-'a']++;
            ans = max(ans , hash['a'-'a']+hash['e'-'a']+hash['i'-'a']+hash['o'-'a']+hash['u'-'a']);
        }
        return ans ; 
    }
};
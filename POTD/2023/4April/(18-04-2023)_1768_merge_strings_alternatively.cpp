// https://leetcode.com/problems/merge-strings-alternately/








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
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(),n2 = word2.length();
        int i = 0 , j = 0 ; 
        string ans = "" ;
        while(i<n1 || j<n2)
        {
            if(i<n1)
                ans+=word1[i++];
            if(j<n2)
                ans+=word2[j++];
        }
        return ans ;
    }
};










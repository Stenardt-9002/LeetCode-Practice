// https://leetcode.com/problems/word-break/?envType=study-plan&id=dynamic-programming-i





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



bool wordBreak(string s, vector<string>& wordDict) 
{
    if(wordDict.size()==0)
        return false ;
    int n = s.length();
    unordered_set<string> hash_string ;
    for(auto c : wordDict)
        hash_string.insert(c);

    vector<bool> dp1(n+1 , false);
    dp1[0] = true ;
    for (int i = 1; i < n+1; i++)
        for (int j = i - 1; j >= 0; j--)
            if(dp1[j])//#match string 0 to j-1 was ok now check j to i-1 substring (indeing inclusive on both side)
                if(hash_string.find(s.substr(j,i-j))!=hash_string.end())
                {
                    dp1[i] = true ;
                    j = -1 ;
                }
        

    return dp1[n]    ;
}











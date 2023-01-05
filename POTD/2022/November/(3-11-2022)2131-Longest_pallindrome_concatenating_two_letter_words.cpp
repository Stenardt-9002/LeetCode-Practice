// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/







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






int longestPalindrome(vector<string>& words) 
{
    int ans1 = 0 ;
    string reverse_str ;
    multiset<string> setwords;
    vector<int>hashpair(26,0);
    for (auto str:words)
    {
        if(str[0]==str[1])
            hashpair[str[0]-'a']++;

        else 
        {
            reverse_str = str ;
            reverse(reverse_str.begin(),reverse_str.end());
            if(setwords.find(reverse_str)==setwords.end())
                setwords.insert(str);
            else 
            {
                ans1+=4 ;
                setwords.erase(setwords.find(reverse_str));
            }
        }
    }
    bool one_odd_allowed = true ;
    for (int i1 = 0; i1 < 26; i1++)
    {
        if (hashpair[i1]%2&&one_odd_allowed)
        {
            one_odd_allowed = false ;
            ans1+=2 ;//one odd
        }
        int add = (hashpair[i1]/2);
        ans1+=(add*4);
    }
    
        
    return ans1 ;

}


//better

int longestPalindrome(vector<string>& words) 
{
    int ans1 = 0 ;
    int ind1 = 0 , ind2 =0;
    vector<vector<int>>hashpair(26,vector<int>(26,0));
    for (auto str:words)
    {
        ind1 = str[0]-'a';
        ind2 = str[1]-'a';
        if(hashpair[ind2][ind1])
        {
            ans1+=4;
            hashpair[ind2][ind1]--;
        }
        else 
            hashpair[ind1][ind2]++;
    }
    bool one_odd_allowed = true ;
    for (int i1 = 0; i1 < 26 && one_odd_allowed; i1++)
        if(hashpair[i1][i1])
        {
            one_odd_allowed = false ;
            ans1+=2;
        }
        
    return ans1 ;

}
















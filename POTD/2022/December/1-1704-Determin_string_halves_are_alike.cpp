// https://leetcode.com/problems/determine-if-string-halves-are-alike/









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



bool halvesAreAlike(string s) 
{
    unordered_set<char> hash_vowels = {'a','e','i','o','u','A','E','I','O','U'}    ;
    int vowel_fisrt_part = 0 ,vowel_second_part = 0 ;
    int n = s.length();
    for (int i = 0; i < n/2; i++)
        if(hash_vowels.find(s[i])!=hash_vowels.end())
            vowel_fisrt_part++ ;

    for (int i = n/2; i < n; i++)
        if(hash_vowels.find(s[i])!=hash_vowels.end())
            vowel_second_part++ ;

    return vowel_fisrt_part == vowel_second_part;    

    
}



















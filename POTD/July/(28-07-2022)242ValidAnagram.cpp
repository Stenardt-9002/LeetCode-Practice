// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1




    bool isAnagram(string s, string t) 
    {
        vector<int> hash1(26,0)    ,hash2(26,0);
        for(auto cha : s)
            hash1[cha-'a']++ ;
        for(auto cha : t)
            hash2[cha-'a']++ ;
        
        for(int i1 = 0 ; i1<26 ; i1++)
            if(hash1[i1]!=hash2[i1])
                return false ;
        return true ;
            
        
    }
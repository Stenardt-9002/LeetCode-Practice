
// https://leetcode.com/problems/first-unique-character-in-a-string/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);







    int firstUniqChar(string s) 
    {
        vector<int>has_char(26,0);
        // int i1 = 0 ;
        // int n = s.length();
        // for(int i1 = 0 ; i1<n ; i1++)
        for(auto ch : s)
            has_char[ch-'a']++;
        int i1=0 ;
        for(auto ch : s)
            if(++i1&&has_char[ch-'a']==1)
                return i1-1  ;
        
        return -1;    
        
    }
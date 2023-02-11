






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
    bool string_compare(string a1 , string b1,unordered_map<char,char>&map_duct)
    {
        int i = 0;
        int n = a1.length();
        int m = b1.length();
        for (i = 0; i < min(n,m); i++)
            if(map_duct[a1[i]]<map_duct[b1[i]])
                return true ;
            else if(map_duct[a1[i]]>map_duct[b1[i]])
                return false ;

        if(n>m)
            return false ;
        return true;

    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        int i = 0 ,n = words.size();
        unordered_map<char,char> map_dict; 
        for(auto c: order)
            map_dict[c] = ++i ;
        
        for(int i=0;i<n-1;i++)
            if(string_compare(words[i],words[i+1],map_dict)==false)
                return false ;

        return true ;
    }
};
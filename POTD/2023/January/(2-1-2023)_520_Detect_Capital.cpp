

// https://leetcode.com/problems/detect-capital/description/









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
    bool capital(char ch)
    {
        return ch>='A'&&ch<='Z';
    }
    bool detectCapitalUse(string word) 
    {
        int n = word.length();
        if(n==1)
            return true ;
        bool first_capital = capital(word[0]);    
        
        // if(word[0]>="A" && word[0]<="Z")
        //     first_capital = true ;
        bool toggle = capital(word[1]) ;
        bool ans = true ;
        for(int i = 2 ;word[i];++i)
            if((toggle^capital(word[i])))
                return false ;
        
        if(!first_capital && capital(word[1]))
            return false ;

        return true ;
    }
};
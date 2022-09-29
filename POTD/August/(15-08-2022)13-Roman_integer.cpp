// https://leetcode.com/problems/roman-to-integer/







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






int romanToInt(string s) 
{
    if(s.empty())
        return 0 ;

    unordered_map<char,int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
    
    int length1 = s.length()-1;
    int ans1 = 0 ;
    for (int i1 = 0; i1<length1; i1++)
        if(table[s[i1]]<table[s[i1+1]])
            ans1-=table[s[i1]] ;
        else 
            ans1+=table[s[i1]] ;

    return ans1+table[s[length1]] ;
}



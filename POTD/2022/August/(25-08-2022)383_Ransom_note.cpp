// https://leetcode.com/problems/ransom-note/ 






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




bool canConstruct(string ransomNote, string magazine) 
{
    int n = magazine.size();
    vector<int>hash_s(26,0);
    for(int i1 = 0 ; i1<n ; i1++)    
        hash_s[magazine[i1]-'a']++ ;
    
    for (auto ch:ransomNote )
        if(--hash_s[ch-'a']<0)
            return false ;
    
    return true ;
}






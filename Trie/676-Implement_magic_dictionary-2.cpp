

// https://leetcode.com/problems/implement-magic-dictionary/










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

const long long int mod2 =  1e18 ;


class MagicDictionary {
public:
    unordered_set<string> hash ;
    MagicDictionary() {
        hash = {};
    }
    
    void buildDict(vector<string> dictionary) 
    {
        for(auto word:dictionary)    
            hash.insert(word);
    }
    
    bool search(string searchWord) 
    {
        for (int i1 = 0; searchWord[i1]; i1++)
        {
            char c= searchWord[i1];
            for (int ch = 'a'; ch <='z'; ch++)
            {
                if(ch==c)
                    continue ;

                searchWord[i1] = ch;
                if(hash.find(searchWord)!=hash.end())
                    return true ;
            }
            
            searchWord[i1] = c;
        }
        return false ;
    }
};


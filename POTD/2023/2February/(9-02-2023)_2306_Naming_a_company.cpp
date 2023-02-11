



// https://leetcode.com/problems/naming-a-company/










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












// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) 
//     {
//         long long int n = ideas.size()    ;
//         long long int count = (n-1)*(n)/2 ;
//         set<string> hash_word(ideas.begin() , ideas.end());
//         for(int i = 0;i<n;i++)
//         {
//             for(int j = i+1 ;j<n;j++)
//             {
//                 string word1 = ideas[i];
//                 string word2 = ideas[j];
//                 char swap_t = word1[0];
//                 word1[0] = word2[0] ; 
//                 word2[0] = swap_t ; 
//                 if(hash_word.find(word1)!=hash_word.end() || hash_word.find(word2)!=hash_word.end())
//                     count-- ;
//             }
//         }
//         return 2*count ;
//     }
// };



class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long int n = ideas.size()    ;
        long long int count = 0;
        unordered_set<string> hash_string[26] ;
        
        for(auto s : ideas)
            hash_string[s[0]-'a'].insert(s.substr(1));

        
        for (int i = 0; i < 26; i++)
            for (int j = i+1; j < 26; j++)
            {
                long long int c1 = 0 , c2 = 0 ;
                for(auto c:hash_string[i])                
                    if(!hash_string[j].count(c))
                        c1++ ;
                
                for(auto c:hash_string[j])                
                    if(!hash_string[i].count(c))
                        c2++ ;
                
                count+=(c1*c2);
            }

        return 2*count ;
    }
};
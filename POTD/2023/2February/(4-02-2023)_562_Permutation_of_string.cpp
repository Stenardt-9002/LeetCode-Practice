// https://leetcode.com/problems/permutation-in-string/










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





bool correct(vector<int> hash_1 ,vector<int> hash_2)
{
    for (int i = 0; i < 26; i++)
        if(hash_1[i]!=hash_2[i])
            return false ;

    return true ;    
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();
        vector<int>hash1_26(26,0)   ,hash2_26(26,0)  ;
        
        for(auto c : s1)
            hash1_26[c-'a']++;

        for (int i = 0; i < n; i++)
            hash2_26[s2[i]-'a']++;

        if(correct(hash1_26,hash2_26))
            return true ;
        for (int i = n; i < m; i++)
        {
            hash2_26[s2[i-n]-'a']--;
            hash2_26[s2[i]-'a']++;

            if(correct(hash1_26,hash2_26))
                return true ;
            
        }
                
        return false ;


    }
};
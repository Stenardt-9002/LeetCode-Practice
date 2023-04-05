
// https://leetcode.com/problems/scramble-string/description/



// https://leetcode.com/problems/reducing-dishes/solutions/?orderBy=most_votes

// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/solutions/?orderBy=most_votes
// https://leetcode.com/problems/longest-cycle-in-a-graph/description/








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














bool util(unordered_map<string ,int>&map1 , string s1 , string s2)
{

        int len1 = s1.length() ; 
        int len2 = s2.length() ; 
        if(len1==0||len2==0)
            return map1[s1+s2] = true ;
        if(s1==s2)  
            return map1[s1+s2] = true ;
        if(len1!=len2)
            return map1[s1+s2] =false ;
        if(map1.count(s1+s2))
            return map1[s1+s2];
        vector<int> hash(26,0);
        for(int i = 0 ; i<len1 ; i++)
            hash[s1[i]-'a']++ , hash[s2[i]-'a']--;
        for(int i = 0 ; i<26;i++)
            if(hash[i]!=0)
                return map1[s1+s2] = false ;
        
        for(int part = 1 ; part<len1 ; part++)
            if( (util(map1,s1.substr(0,part),s2.substr(0,part))&&util(map1,s1.substr(part),s2.substr(part))) || (util(map1,s1.substr(0,part),s2.substr(len1-part))&&util(map1,s1.substr(part),s2.substr(0,len1-part)))  )
                return map1[s1+s2] = true ;
            
        
        return map1[s1+s2] = false ;
}


class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        unordered_map<string ,int>map1;
        return util(map1,s1,s2);
    }
};
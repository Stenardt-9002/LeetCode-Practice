

// https://leetcode.com/problems/determine-if-two-strings-are-close/









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





bool closeStrings(string word1, string word2) 
{
    vector<int> hash1(26,0) ,hash1_letter(26,0)     ;
    vector<int> hash2(26,0) ,hash2_letter(26,0)     ;
    for (int i = 0; word1[i]; i++)
        hash1[word1[i]-'a']++ , hash1_letter[word1[i]-'a']=1 ;

    for (int i = 0; word2[i]; i++)
        hash2[word2[i]-'a']++ , hash2_letter[word2[i]-'a']=1 ;
    
    sort(hash1.begin(),hash1.end());
    sort(hash2.begin(),hash2.end());

    return (hash1==hash2)&&(hash1_letter == hash2_letter);

}




















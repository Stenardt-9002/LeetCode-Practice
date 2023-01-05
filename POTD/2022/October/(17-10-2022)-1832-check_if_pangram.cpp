
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/





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




bool checkIfPangram(string sentence) 
{
    int count = 26;
    vector<int>hash_letter(26,0)    ;
    for (int i1 = 0; sentence[i1]; i1++)
        count-=(hash_letter[sentence[i1]-'a']++==0);


    return count==0 ;    
}





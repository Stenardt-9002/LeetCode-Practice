// https://leetcode.com/problems/unique-morse-code-words/








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

static vector<string> map_morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(vector<string>& words) 
{

    unordered_set<string> count_str ;
    for(auto word: words )
    {
        string formed = "";
        for(auto ch : word)
            formed+=map_morse[ch-'a'];
        count_str.insert(formed);
    }
    return count_str.size();
}




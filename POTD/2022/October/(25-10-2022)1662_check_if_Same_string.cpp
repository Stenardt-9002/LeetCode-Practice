// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/




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








bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string arr1 = "",arr2 = "";
    for(auto word : word1)
        arr1+=word ;

    for(auto word : word2)
        arr2+=word ;
    return arr1==arr2 ;    
}



















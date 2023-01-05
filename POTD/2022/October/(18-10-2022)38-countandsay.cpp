
// https://leetcode.com/problems/count-and-say/submissions/




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









string countAndSay(int n) 
{
    if(n==1)    
        return "1";

    string prev_string = countAndSay(n-1);

    string ans1 = "";
    char buffer_char =prev_string[0];
    int current_count = 1 ;
    for (int i1 = 1; prev_string[i1]; i1++)
        if(prev_string[i1]==buffer_char)
            current_count++ ;
        else 
        {
            ans1+=to_string(current_count)+buffer_char;
            buffer_char = prev_string[i1];
            current_count= 1;
        }

    ans1+=to_string(current_count)+buffer_char ;    
    return ans1 ;
}
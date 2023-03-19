// https://leetcode.com/problems/string-compression/description/














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


class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int i = 0 ;
        int n = chars.size();
        int last_index = 0 ;
        int current_count = 1;
        if(n==1)
            return 1 ;
        while(i<n)
        {
            current_count = 1 ;
            while(i<n-1 && chars[i]==chars[i+1])
                ++i , current_count++;
            
            chars[last_index++] =  chars[i++];
            if(current_count!=1)
            {
                string digit = to_string(current_count);
                for(char c : digit)
                    chars[last_index++] = c;
            }
        }
        
        return last_index ;
    }
};
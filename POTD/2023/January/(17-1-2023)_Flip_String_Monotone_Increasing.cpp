






// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/




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
    int minFlipsMonoIncr(string s) 
    {
        int n = s.length()    ;
        int ones_count = 0 , zero_count = 0 ;
        for (int i = 0; i < n; i++)
            zero_count+=(s[i]=='0') ;
        
        ones_count = n-zero_count ; 
        int ans = 0;
        int cur_zreo = 0 ,cur_one = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='0')
                cur_zreo++;
            else 
                cur_one++;
            
            ans = min({ans , cur_one ,zero_count-cur_zreo });
        }
        


        return ans ;

    }
};

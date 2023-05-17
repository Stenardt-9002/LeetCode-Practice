// https://leetcode.com/problems/add-digits/







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
    int addDigits(int num) 
    {
        int ans = 0 ;
        while(num>0)
        {
            ans += (num%10);
            num/=10 ;
            while(ans>9)
                ans = ans%10+ans/10;
        }
        return ans ;
    }
};








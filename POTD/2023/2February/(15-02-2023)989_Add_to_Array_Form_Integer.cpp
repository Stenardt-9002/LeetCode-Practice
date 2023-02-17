// https://leetcode.com/problems/add-to-array-form-of-integer/














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







int length_n(int val)
{
    int length = 0 ;
    while (val>0)
    {
        length++ ;
        val/=10 ;    
    }
    return length ;
}

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int n = num.size()    ;
        int m = length_n(k);
        int i = n , j = m ;
        int carry = 0 ;
        int val_k = k ;
        vector<int> ans ; 
        while (i>0 && j>0)
        {
            i-- ; j-- ;
            int val = num[i]+(val_k%10)+carry ;
            val_k/=10 ;
            carry = val/10 ;
            ans.push_back(val%10);
        }
        while(i>0)
        {
            i-- ;
            int val = num[i]+carry ;
            carry = val/10 ;
            ans.push_back(val%10);
        }
        while (j>0)
        {
            j-- ;
            int val = (val_k%10)+carry ;
            val_k/=10 ;
            carry = val/10 ;
            ans.push_back(val%10);
        }
        if(carry>0)
            ans.push_back(1);
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};



























// https://leetcode.com/problems/utf-8-validation/








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


bool validUtf8(vector<int>& data) {
    int count = 0 ;
    for(auto x:data)
    {
        if(count==0)
        {
            if((x>>5)==0b110) count=1 ;
            else if((x>>4)==0b1110) count=2 ;
            else if((x>>3)==0b11110) count=3 ;
            else if(x>>7) return false ;
        }
        else 
        {
            if((x>>6)!=0b10) return false ;
            count-- ;
        }
    }
    return count==0 ;
}

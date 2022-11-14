// https://leetcode.com/problems/orderly-queue/









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

int maximum69Number (int num) 
{
    int ans1 = num;
    int pos = -1;
    int cur_pos = 0 ;
    while(num!=0)
    {
        if(num%10==6)
            pos = cur_pos ;
        cur_pos++ ;
        num/=10 ;
    }
    return (pos==-1)?(ans1):(ans1+3*pow(10,pos));
}
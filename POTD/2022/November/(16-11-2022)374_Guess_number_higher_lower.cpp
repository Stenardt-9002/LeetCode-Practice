// https://leetcode.com/problems/guess-number-higher-or-lower/









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




int guessNumber(int n) 
{
    ll low = 1 , high = n;
    ll mid ;
    while(low<high)
    {
        mid = (low+high+1)>>1;
        if(guess(mid)==0)
            return mid ;
        else if(guess(mid)==1)
            low = mid+1;
        else 
            high = mid-1;
    }
    return low ;
}





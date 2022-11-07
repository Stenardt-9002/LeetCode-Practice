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




string orderlyQueue(string s, int k) 
{
    if(k>1)
    {
        sort(s.begin(),s.end());
        return s ;
    }
    string ans1 = s;
    for (int i1 = 1; i1 < s.length(); i1++)
        ans1 = min(ans1 , s.substr(i1)+s.substr(0,i1));

    return ans1 ;    
}












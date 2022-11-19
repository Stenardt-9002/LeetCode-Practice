// https://leetcode.com/contest/weekly-contest-318/problems/maximum-sum-of-distinct-subarrays-with-length-k/








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



long long totalCost(vector<int>& costs, int k, int candidates) 
{
    ll n = costs.size();
    if(n<2*candidates+k)
    {
        sort(costs.begin(),costs.end());
        ll ans1 = 0;
        for (ll i1 = 0; i1 < k; i1++)
            ans1+=costs[i1]        ;

        return ans1 ;
    }
    multiset<ll> s1 ,s2 ;
    ll ans1 = 0, taken_set1 = 0 , taken_set2 = 0;
    for (ll i1 = 0; i1 < candidates; i1++)
    {
        s1.insert(costs[i1])    ;
        s2.insert(costs[n-1-i1]);
    }
    ll ptr1 = candidates ,ptr2 = n-1-candidates;
    while(k--)
    {
        if(*(s1.begin())<=*(s2.begin()))
        {
            ans1+=*(s1.begin());
            s1.erase(s1.begin());
            s1.insert(costs[ptr1++]);
        }
        else 
        {
            ans1+=*(s2.begin());
            s2.erase(s2.begin());
            s2.insert(costs[ptr2--]);
        }
    }
    return ans1 ;



}



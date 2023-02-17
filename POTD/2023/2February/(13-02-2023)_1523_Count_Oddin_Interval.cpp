// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/














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
    int countOdds(int low, int high) {
        int n = high-low+1 ;
        int count = n>>1;
        return (n%2)?((low%2)?count+1:count):count;
    }
};




























// https://leetcode.com/contest/weekly-contest-313/problems/number-of-common-factors/


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






int divCount(int n)
{
    vector<bool> hash(n + 1,true);
    for (int p = 2; p * p < n; p++)
        if (hash[p] == true)
            for (int i = p * 2; i < n; i += p)
                hash[i] = false;

    int total = 1;
    for (int p = 2; p <= n; p++) 
    {
        if (hash[p]) 
        {
            int count = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}
class Solution {
public:
    int commonFactors(int a, int b) {
        return (divCount(__gcd(a,b)));
    }
};
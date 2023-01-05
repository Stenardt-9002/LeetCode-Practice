// https://leetcode.com/problems/binary-trees-with-factors/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        ll ans1 = 0, MOD1 = pow(10, 9) + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp1;
        for (int i = 0; i < arr.size(); ++i) 
        {
            dp1[arr[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (arr[i] % arr[j] == 0)
                    dp1[arr[i]] = (dp1[arr[i]] + dp1[arr[j]] * dp1[arr[i] / arr[j]]) % MOD1;

            ans1 = (ans1 + dp1[arr[i]]) % MOD1;
        }
        return ans1;





    }




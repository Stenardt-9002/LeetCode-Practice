// https://leetcode.com/problems/reducing-dishes/description/

















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
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int ans = 0 ;
        int sum1 = 0 ;
        int cur_sum = 0;
        while(n--)
        {
            sum1+=satisfaction[n];
            cur_sum+=sum1 ;
            ans = max(ans, cur_sum);
        }
        return ans ; 
    }
};
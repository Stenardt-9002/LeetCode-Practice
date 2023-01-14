// https://leetcode.com/problems/gas-station/







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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
                int n = gas.size()    ;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
            sum1 += (gas[i]-cost[i]);

        if(sum1<0)
            return -1 ;

        int start = 0;        
        sum1 = 0 ;
        for (int i = 0; i < n; i++)
        {
            sum1 += (gas[i]-cost[i]);
            if(sum1<0)
            {
                sum1 = 0;
                start = i+1 ;
            }
        }

        return start ;
    }
};























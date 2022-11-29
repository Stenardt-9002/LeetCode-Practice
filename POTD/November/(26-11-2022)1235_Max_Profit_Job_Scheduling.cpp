
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/








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













int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
{
    int n = startTime.size()    ;
    vector<vector<int>> array ;
    for (int i = 0; i < n; i++)
        array.push_back({endTime[i],startTime[i],profit[i] })   ;

    sort(array.begin(),array.end());

    map<int,int> dp1 ;
    dp1[0] = 0 ;

    for (auto i : array )
    {
        int cur = (--dp1.upper_bound(i[1]))->second+i[2];
        if(cur>(--dp1.end())->second)
            dp1[i[0]] = cur ;
    }
    
    return (--dp1.end())->second ;

}



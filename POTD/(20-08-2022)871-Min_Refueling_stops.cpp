// https://leetcode.com/problems/minimum-number-of-refueling-stops/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
{
    int i = 0, res;
    priority_queue<int>pq;
    for (res = 0; startFuel < target; res++) 
    {
        while (i < stations.size() && stations[i][0] <= startFuel)
            pq.push(stations[i++][1]);
        if (pq.empty()) 
            return -1;
        startFuel += pq.top();
        pq.pop();
    }
    return res;    
}







// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/




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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n = intervals.size();
        int i = 0 ;
        vector<vector<int>> ans ;
        while(i<n && intervals[i][1]<newInterval[0])
            ans.push_back(intervals[i++]);
        //merging
        while(i<n && newInterval[1]>=intervals[i][0])
        {
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max(newInterval[1] , intervals[i][1]);
            i++ ;
        }
        ans.push_back(newInterval);
        while(i<n)
            ans.push_back(intervals[i++]);
        

        return ans ;
    }
};
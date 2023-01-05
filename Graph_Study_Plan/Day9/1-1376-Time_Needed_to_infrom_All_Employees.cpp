
// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=study-plan&id=graph-i




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







static int arrx[] = {-1,-1,-1,0,0,1,1,1};
static int arry[] = {-1,0,1,-1,1,-1,0,1};









class Solution {

public:

    int dfs_util(int src , vector<int>*graph ,vector<int>infortime )
    {
        if(graph[src].size()==0)
            return infortime[src];
        int ans = 0;
        for(auto child : graph[src])
            ans = max(ans , dfs_util(child , graph , infortime ));
        return ans+infortime[src];
    }



    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<int>*graph1 = new vector<int>[n];
        for(int i =0;i<n;i++)
            if(manager[i]!=-1)
                graph1[manager[i]].push_back(i);
        
        int max_ans = dfs_util(headID ,graph1, informTime );
        return max_ans ;
    }
};





// bottom DFS trick good 


class Solution {
public:

    int dfs_util(int src , vector<int>&manager ,vector<int>&infortime )
    {
        if(manager[src]!=-1)
        {
            infortime[src]+=dfs_util(manager[src],manager ,infortime);
            manager[src] = -1 ;
        }
        return infortime[src];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        int max_ans = 0;
        for(int i =0;i<n;i++)
            max_ans = max(max_ans , dfs_util(i , manager , informTime));
        
        return max_ans ;
    }
};
















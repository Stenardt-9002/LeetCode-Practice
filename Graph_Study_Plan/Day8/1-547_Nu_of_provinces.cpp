





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
    void dfs_util(int src , vector<vector<int>>& isConnected , vector<int>&visited) 
    {
        if(!visited[src])
        {
            int n = isConnected.size();
            visited[src] = true ;
            for(int i = 0 ; i<n;i++)
                if(isConnected[src][i]==1 && visited[i]==false)
                    dfs_util(i,isConnected , visited);
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<int> visited(n,false)    ;
        int ans = 0 ;
        for (int i = 0; i < n; i++)
            if(!visited[i] )
            {
                dfs_util(i , isConnected , visited) ;
                ans++ ;
            }
        


        return ans ;
    }
};
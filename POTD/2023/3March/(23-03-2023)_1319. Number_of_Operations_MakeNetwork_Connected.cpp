// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/


























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




int find_dsu(int a , vector<int> & parents)
{
    if(parents[a]==a)
        return a ; 
    return parents[a] = find_dsu(parents[a] , parents);
}

class Solution 
{
public:

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(n-1>connections.size())
            return -1;

        vector<int> parents(n,0);
        for(int i = 0 ; i<n;++i)
            parents[i] = i ;

        for(auto ed: connections)
        {
            int u = find_dsu(ed[0],parents);
            int v = find_dsu(ed[1] ,parents);
            if(u!=v)
                parents[u] = v ;
        }
        int num_of_components = 0 ;

        for(int i = 0 ;i<n;++i)
            num_of_components+=(parents[i]==i);
        return num_of_components-1;
    }

};













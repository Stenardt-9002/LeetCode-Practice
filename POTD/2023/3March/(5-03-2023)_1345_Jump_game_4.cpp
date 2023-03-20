// https://leetcode.com/problems/jump-game-iv/















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
//bfs this
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int,vector<int>>indice_map ; 
        for(int i = 0 ; i<n; ++i)
            indice_map[arr[i]].push_back(i);

        vector<bool> visited(n);
        visited[0] = true ;
        queue<int> q ;
        q.push(0);
        int count = 0 ;
        while(q.size())
        {
            int size = q.size();
            while(size--)
            {
                int i = q.front();
                q.pop();
                if(i==n-1)
                    return count;
                indice_map[arr[i]].push_back(i-1);
                indice_map[arr[i]].push_back(i+1);
                for(int j : indice_map[arr[i]])
                    if(j>=0 && j<n && !visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                indice_map[arr[i]].clear();
            }
            count++;
        }
        return 0 ;
    }
};


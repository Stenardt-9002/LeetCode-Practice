
// https://leetcode.com/problems/keys-and-rooms/?envType=study-plan&id=graph-i




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








    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool>visited(n,false);
        queue<int> q1 ;
        q1.push(0)        ;
        visited[0] = true ;
        while (!q1.empty())
        {
            int front = q1.front();
            q1.pop();
            for(auto child : rooms[front])
                if(!visited[child])
                {
                    q1.push(child);
                    visited[child] = true ;
                }
        }
        return count(visited.begin() , visited.end(),false)==0;  
    }

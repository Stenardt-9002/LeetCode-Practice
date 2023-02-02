










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








class Solution 
{
public:
    void bfs_queue(int src ,vector<int>&distance1 ,vector<int>*graph )
    {
        distance1[src] = 0 ;
        queue<int>q1 ; 
        q1.push(src);
        int cur = 0;
        while(!q1.empty())
        {
            ++cur ;
            int size = q1.size();
            for(int i = 0 ;i<size ; i++)
            {
                int front = q1.front();
                q1.pop();
                for(auto child : graph[front])
                    if(distance1[child]==-1)
                    {
                        distance1[child]=cur ; 
                        q1.push(child);
                    }
            }
        }

    }


    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<int>*graph = new vector<int>[n]    ;
        for(int i = 0 ; i<n;i++)
            if(edges[i]!=-1)
                graph[i].push_back(edges[i]);
        vector<int>distance1(n,-1);
        vector<int>distance2(n,-1);
        bfs_queue(node1 ,distance1 ,graph );
        bfs_queue(node2 ,distance2 ,graph );

        int ans = -1 ;
        int max_distance = INT_MAX ;
        for(int i = 0;i<n;i++)
            if(distance1[i]!=-1&&distance2[i]!=-1)
            {
                if(max(distance1[i],distance2[i])<max_distance)
                {
                    max_distance = max(distance1[i],distance2[i]) ;
                    ans = i ;
                }
            }
        // dtiaply(distance1);
        // dtiaply(distance2);
        return ans ;
    }
};
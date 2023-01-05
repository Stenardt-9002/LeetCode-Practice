// https://leetcode.com/problems/the-skyline-problem/


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

const long long int mod2 =  1e18 ;







vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
{
    vector<vector<int>> ans1  ;
    int ptr = 0 ;
    int n = buildings.size();
    int X_temp = 0 ,height_temp = -1 ;
    priority_queue<pair<int,int>> pq_heap ; //height ,second

    while (ptr<n || !pq_heap.empty())
    {
        X_temp = pq_heap.empty()?buildings[ptr][0]:pq_heap.top().second; //second pt
        if(ptr>=n || buildings[ptr][0]>X_temp)
            while (!pq_heap.empty() && (pq_heap.top().second<=X_temp))
                pq_heap.pop();// no longer in range 

        else 
        {
            X_temp = buildings[ptr][0];
            while(ptr<n && buildings[ptr][0]==X_temp)
            {
                pq_heap.push({buildings[ptr][2],buildings[ptr][1]});
                ptr++ ;
            }

        }            
        height_temp = pq_heap.empty()?0:pq_heap.top().first ;
        if(ans1.empty() || (ans1.back()[1]!=height_temp))
            ans1.push_back({X_temp , height_temp});
    }
    
    return ans1 ;



}



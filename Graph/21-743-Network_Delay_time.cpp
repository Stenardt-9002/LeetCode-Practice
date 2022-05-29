// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int dfs_util(int src ,int &sum, vector<bool> &visiited ,vector<pair<int,int>> *adj )
{
    // cout<<endl<<"DEBIG2 "<<src<<"\n";

    int cur_sum =0;
    if(!visiited[src])
    {
        visiited[src] = true ;
        for(auto child : adj[src])
        {
            if(!visiited[child.first])
            {
            // cout<<endl<<"DEBIG1 "<<child.first<<"\n";
            cur_sum = child.second+dfs_util(child.first ,sum , visiited,adj);
            sum = max(sum,cur_sum);
            }
        }
    }
    return cur_sum ;
}

// int networkDelayTime(vector<vector<int>>& times, int n, int k) 
// {
//     vector<pair<int,int>> *adj = new vector<pair<int,int>>[n];
//     k--;
//     for (auto x : times)
//         adj[x[0]-1].push_back({x[1]-1,x[2]});
    
//     int sum = 0 ;
//     vector<bool>visiited(n,false);
//     dfs_util(k, sum , visiited , adj );
//     delete []adj ;
//     // cout<<endl<<"DEBUG1  ";
//     // for (int i1 = 0; i1 < n; i1++)
//     //     cout<<" "    <<visiited[i1];
//     // cout<<endl ;
//     for(int i1 = 0;i1<n;i1++)
//         if(!visiited[i1])
//             return -1;
//     return sum ;
// }
int networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
    vector<pair<int,int>> *adj = new vector<pair<int,int>>[n];
    k--;

    vector<int>dist_1(n,INT_MAX);
    dist_1[k]=0;
    for(int i1 = 0;i1<n;i1++)
        for (auto x : times)
            {
                int u = x[0]-1;
                int v = x[1]-1;
                int w = x[2];
                if(dist_1[u]!=INT_MAX && dist_1[v]>dist_1[u]+w)
                    dist_1[v] = w+dist_1[u];
            }
    
    
    int sum = 0 ;
    for(int i1 = 0;i1<n;i1++)
        sum = std::max(sum , dist_1[i1]);

    return sum ;
}

int main(int argc, char const *argv[])
{
    int n ,k; 
    vector<vector<int>> times;
    cin>>n ;
    for (int i1 = 0; i1 < n; i1++)
    {
        vector<int>temp1(3);
        cin>>temp1[0]>>temp1[1]>>temp1[2];
        times.push_back(temp1);
    }
    cin>>n>>k;
    cout<<networkDelayTime(times,n,k);
    



    return 0;
}




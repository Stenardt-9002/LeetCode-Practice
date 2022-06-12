
// https://leetcode.com/problems/loud-and-rich/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int dfs_util(int src , vector<int> *garph1 ,vector<int> &min_quiet_val  , vector<int>quiet)
{
    if(min_quiet_val[src]==-1)
    {
        int current_nde = src ; 
        for(auto x : garph1[src])
        {
            int nodes_val = dfs_util(x,garph1,min_quiet_val,quiet);
            if(quiet[current_nde]>quiet[nodes_val])
                current_nde = nodes_val ;
        }

        min_quiet_val[src] = current_nde ;
    }
    return min_quiet_val[src] ;
}



vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
{
    int n = quiet.size();
    vector<int> min_quiet_val(n,-1);

    vector<int> *graph1 = new vector<int>[n];

    for (auto x : richer)
        graph1[x[1]].push_back(x[0]);
    

    for (int i1 = 0; i1 < n; i1++)
        if(min_quiet_val[i1]==-1)
            min_quiet_val[i1] = dfs_util(i1,graph1,min_quiet_val,quiet);
    
    delete []graph1 ;
    return min_quiet_val ;

}

int main(int argc, char const *argv[])
{
    int n ;
    cin>>n;
    vector<int> queit(n+1);
    vector<vector<int>>edges;
    for (int i1 = 0; i1 < n; i1++)
    {
        vector<int>temp(2);
        cin>>temp[0]>>temp[1];
        edges.push_back(temp);
    }

    for (int i1 = 0; i1 <= n; i1++)
        cin>>queit[i1];

    vector<int> ans1 = loudAndRich(edges,queit);
    cout<<endl;
    for(auto x : ans1)
        cout<<" "<<x ; 
    return 0;
}




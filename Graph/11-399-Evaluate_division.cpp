
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

// https://leetcode.com/problems/evaluate-division/

void dfs_util(string start, string end ,double &ans1 , map<string,double> &map1 ,map<string,vector<string>> &graph, map<string,bool> &visited1 , bool &found)
{
    visited1[start] = true;//done with all children 
    if(found)
        return ; //
    for(auto neig : graph[start])
        if(!visited1[neig])
        {
            ans1*=map1[start+"->"+neig] ;
            if(end==neig)
            {
                found = true ; 
                return ;
            }
            dfs_util(neig,end,ans1,map1,graph,visited1,found);
            if(found)
                return ;
            else 
                ans1/=map1[start+"->"+neig] ;
        }
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
{
    map<string,vector<string>> graph1 ;
    map<string,double > mp1 ;
    vector<double> ans1 ;
    int i1;
    //proces inputs 
    for (i1 = 0; i1 < equations.size(); i1++)
    {
        string u = equations[i1][0] ;
        string v = equations[i1][1] ;
        graph1[u].push_back(v);
        graph1[v].push_back(u);
        mp1[u+"->"+v] = values[i1];
        mp1[v+"->"+u] = (1.0)/(values[i1]);
    }
    //each query
    for (i1 = 0; i1 < queries.size(); i1++)
    {
        string strat = queries[i1][0] ;
        string end   = queries[i1][1] ;

        if(graph1.find(strat)==graph1.end()||graph1.find(end)==graph1.end())
            ans1.push_back(-1);

        else
        {
            double ansval = 1;
            map<string,bool>vsiited ;//for each query
            bool done = false ;
            if(strat==end)//same value
                done = true ;
            else 
                dfs_util(strat , end,ansval , mp1, graph1 , vsiited,done);

            if(done)
                ans1.push_back(ansval);
            else 
                ans1.push_back(-1);
        }
        
    }
    return ans1 ;
 
}









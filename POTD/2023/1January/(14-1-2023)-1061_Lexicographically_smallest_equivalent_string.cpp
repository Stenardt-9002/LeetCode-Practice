


// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/




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
    int find_f(int x , vector<int>&pare)
    {
        if(pare[x]==-1)
            return x ; 
        return pare[x] = find_f(pare[x] , pare);
    }

    void DSU_util(int x , int y , vector<int>&par)
    {
        x = find_f(x , par);
        y = find_f(y , par);
        if(x!=y)
            par[max(x,y)] = min(x,y);

    }


    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        vector<int>pare(26,-1)    ;
        for (int i = 0; s1[i]; i++)
            DSU_util(s1[i]-'a' , s2[i]-'a' ,pare);
        
        for (int i = 0; i < baseStr[i]; i++)
            baseStr[i] = find_f(baseStr[i]-'a',pare)+'a';


        return baseStr ;
    }
};
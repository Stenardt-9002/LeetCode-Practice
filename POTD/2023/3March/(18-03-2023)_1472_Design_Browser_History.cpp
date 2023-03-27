// https://leetcode.com/problems/design-browser-history/


















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
















class BrowserHistory {
public:
    int cur_pos = 0  ; 
    vector<string> array1 ; 
    BrowserHistory(string homepage) 
    {
        this->array1.push_back(homepage);
        this->cur_pos = 0;
    }
    
    void visit(string url) 
    {
        this->array1.resize(++cur_pos);//clear after stuff
        this->array1.push_back(url);
    }
    
    string back(int steps) 
    {
        cur_pos = max(0, cur_pos-steps) ;
        return this->array1[cur_pos];
    }
    
    string forward(int steps) 
    {
        cur_pos = min(((int)(this->array1.size())-1), cur_pos+steps) ;
        return this->array1[cur_pos];
    }
};

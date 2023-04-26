

// https://leetcode.com/problems/accounts-merge/description/










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
    string find_DSU(string email,map<string,string>&parents)
    {
        if(email==parents[email])
            return email ; 
        return find_DSU(parents[email] , parents);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        vector<vector<string>> ans ; 
        map<string,string> name , parents ; 
        map<string , set<string>> collection ;
        for(int i = 0 ; i<n ; i++)
            for(int j = 1 ; j<accounts[i].size();j++)
            {
                parents[accounts[i][j]] = accounts[i][j];
                name[accounts[i][j]] = accounts[i][0];
            }
        

        for(int i = 0 ; i<n ; i++)
        {
            string p = find_DSU(accounts[i][1],parents);
            for(int j = 2 ; j<accounts[i].size();j++)
                parents[find_DSU(accounts[i][j],parents)] = p;
        }

        for(int i = 0 ; i<n ; i++)
            for(int j = 1 ; j<accounts[i].size();j++)
                collection[find_DSU(accounts[i][j],parents)].insert(accounts[i][j]);
        
        for(auto p : collection)
        {
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin() , name[p.first]) ; 
            ans.push_back(emails);
        }
        
        return ans ; 
    }
};
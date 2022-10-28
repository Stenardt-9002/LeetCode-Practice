




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




vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string,vector<int>> map1 ;
    int n = strs.size();
    string index = "";
    for (int i1 = 0; i1 < n; i1++)
    {
        index = strs[i1];
        sort(index.begin(),index.end());
        map1[index].push_back(i1);
    }
    vector<vector<string>> ans1 ;
    for(auto key : map1)
    {
        vector<string> temp1 ;
        for(int i:key.second)
            temp1.push_back(strs[i]);
        
        ans1.push_back(temp1);
    }

    return ans1 ;
}




vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string,vector<string>> map1 ;
    int n = strs.size();
    string index = "";
    for (int i1 = 0; i1 < n; i1++)
    {
        index = strs[i1];
        sort(index.begin(),index.end());
        map1[index].push_back(strs[i1]);
    }
    vector<vector<string>> ans1 ;
    for(auto key : map1)
    {
        vector<string> temp1 ;
        for(auto i:key.second)
            temp1.push_back(i);
        
        ans1.push_back(temp1);
    }

    return ans1 ;
}





vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    map<string,vector<string>> map1 ;
    int n = strs.size();
    string index = "";
    for (int i1 = 0; i1 < n; i1++)
    {
        index = strs[i1];
        sort(index.begin(),index.end());
        map1[index].push_back(strs[i1]);
    }
    vector<vector<string>> ans1 ;
    for(auto key : map1)
    {
        vector<string> temp1 ;
        for(auto i:key.second)
            temp1.push_back(i);

        ans1.push_back(temp1);
    }

    return ans1 ;

}







// https://leetcode.com/problems/top-k-frequent-words/








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

    vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string,int> map1 ;
            vector<string> ans1 ;
            // sort(words.begin(),words.end());
            for(auto x : words)
                map1[x]++ ;

            auto cmp = [](pair<string,int> a, pair<string,int> b) {if(a.second==b.second)
                return a.first<b.first; else return a.second>b.second ;};    
                // auto cmp = [](pair<string,int> a, pair<string,int> b) {return a.second>b.second ;};    
            multiset<pair<string,int>,decltype(cmp)> heap1(cmp) ;
        
            for (auto pair1 : map1)
            heap1.insert({pair1.first,pair1.second});

            while (!heap1.empty() && k-- )
            {
                pair<string,int> output = *(heap1.begin());
                heap1.erase(heap1.begin());
                ans1.push_back(output.first);
            }
            

            return ans1 ;
    }




// https://leetcode.com/problems/time-based-key-value-store/





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


class TimeMap {
public:
    unordered_map<string , map<int,string>>map1 ;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        // if(this->map1.find(key)!=this->map1.end())
        // {
        //     map<int,string>time_to_key = 
        // }
        // else 
        // {
        //     map<int,string>time_to_key  ;
        //     time_to_key[timestamp] = value ;
        //     this->map1[key] = time_to_key ;
        // }
        this->map1[key][timestamp] = value ;
    }
    
    string get(string key, int timestamp) 
    {
        if(this->map1.find(key)!=this->map1.end())
        {
            map<int,string>time_to_key = this->map1[key];
            if(time_to_key.find(timestamp)!=time_to_key.end())
                return time_to_key[timestamp];
            else 
            {
                auto it = time_to_key.lower_bound(timestamp);
                if(it!=time_to_key.begin())
                {
                    --it ;
                    return it->second ;
                }
            }

            
        }
        return "";
    }
};


class TimeMap {
public:
    unordered_map<string , map<int,string>>map1 ;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        this->map1[key][timestamp] = value ;
    }
    
    string get(string key, int timestamp) 
    {
        auto it = this->map1[key].upper_bound(timestamp);
        return it==this->map1[key].begin()?"":(--it)->second ;
    }
};


// unordered_map<string, vector<pair<int, string>>> m;
// void set(string key, string value, int timestamp) {
//   m[key].push_back({ timestamp, value });
// }
// string get(string key, int timestamp) {
//   auto it = upper_bound(begin(m[key]), end(m[key]), pair<int, string>(timestamp, ""), [](
//     const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });
//   return it == m[key].begin() ? "" : prev(it)->second;
// }

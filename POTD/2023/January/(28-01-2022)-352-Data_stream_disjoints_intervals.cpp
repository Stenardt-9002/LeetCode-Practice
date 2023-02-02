


// https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/













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











class SummaryRanges {
public:
    map<int,int> dict1 ;
    SummaryRanges() {
        
    }
    
    void addNum(int value) 
    {
        auto search = dict1.lower_bound(value);
        bool merged = false ;
        if(search!=dict1.begin())
        {
            auto last = search ;
            last-- ;
            if(last->second+1>=value)
            {
                merged = true ;
                last->second = max(last->second , value);
            }
        }

        if(search!=dict1.end())
        {
            if(search->first-1<=value)
            {
                if(merged)
                {
                    auto last = search ;
                    last-- ;
                    if(last->second>=search->first-1)
                    {
                        last->second = max(last->second , search->second);
                        dict1.erase(search);
                    }
                }
                else 
                {
                    merged = true ;
                    if(search->first!=value)
                    {
                        pair<int,int> p = *search ;
                        p.first = min(p.first , value);
                        search = dict1.insert(search,p);
                        if(++search!=dict1.end())
                            dict1.erase(search);

                    }
                }


            }
        }

        if(!merged)
            dict1.insert(search , {value , value});



    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>>ans ;
        for(auto p:dict1)    
            ans.push_back({p.first,p.second});
        return ans ;
    }
};








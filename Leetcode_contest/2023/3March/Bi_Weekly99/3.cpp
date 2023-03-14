

// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/














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
    int countWays(vector<vector<int>>& ranges) 
    {
        set<pair<int,int>> s1 ;
        for(auto vec : ranges)
            s1.insert({vec[0], vec[1]});
        
        int count = 0 ;
        while (!s1.empty())
        {
            pair<int,int> p = *(s1.begin());
            pair<int,int> p2 = {-1 ,-1};
            s1.erase(s1.begin());
            if(s1.size())
            {
                p2 = *(s1.begin());
                s1.erase(s1.begin());
            }
            
            if(!(p2.first==-1 && p2.second ==-1))
            {
                if(p.second>=p2.first)
                {
                    p2.first = p.first;
                    p2.second = max(p.second , p2.second);
                }
                else 
                    count++ ;
                s1.insert(p2);
            }
            else 
                count++ ;
        }
        long long int ans = 1 ;
        for (int i = 0; i < count; i++)
        {
            ans*=2 ;
            ans = ans%MOD1 ;
        }
        return (int)(ans);
    }
};





























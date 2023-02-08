




// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/









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
    int count(int freq )
    {
        if(freq<2)
            return -1 ;
        
        int count = freq/3;
        
        count+=((freq%3)!=0);
        return count ;
    }
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int,int>map_1 ;
        int ans = 0 ;
        for (auto i:tasks)    
            map_1[i]++;
        for(auto keys:map_1)
        {
            int temp = count(keys.second);
            if(temp==-1)
                return -1;
            ans+=temp;
        }
        return ans ; 
    }
};
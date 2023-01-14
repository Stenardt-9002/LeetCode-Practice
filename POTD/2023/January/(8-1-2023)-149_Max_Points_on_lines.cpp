// https://leetcode.com/problems/max-points-on-a-line/







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
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<string,int>map1 ;
            int couter = 1 ;
            for (int j = i+1; j < n; j++)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                    couter++;
                else 
                {
                    int dx = points[j][0]-points[i][0];
                    int dy = points[j][1]-points[i][1];
                    int g = __gcd(dx,dy);

                    map1[to_string(dx/g)+'_'+to_string(dy/g)]++;
                }
            }
            ans = max(ans, couter)            ;
            for(auto itr:map1)
                ans = max(ans , itr.second+couter);
        }
        return ans ;
    }
};
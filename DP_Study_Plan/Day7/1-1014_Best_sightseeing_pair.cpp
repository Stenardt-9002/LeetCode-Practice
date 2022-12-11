// https://leetcode.com/problems/best-sightseeing-pair/?envType=study-plan&id=dynamic-programming-i








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






int maxScoreSightseeingPair(vector<int>& values) 
{
    int n = values.size();
    int ans1 = INT_MIN ;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            ans1 = max(ans1 , values[j]+values[i]+j-i)            ;
        
    return ans1 ;    
}





    int maxScoreSightseeingPair(vector<int>& values) 
    {

        int res = 0, cur = 0;
        for (int a: values) 
        {
            res = max(res, cur + a);
            cur = max(cur, a) - 1;
        }
        return res;
    }







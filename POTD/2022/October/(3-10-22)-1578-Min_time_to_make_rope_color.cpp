

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

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






int minCost(string colors, vector<int>& neededTime) 
{
    int n = neededTime.size();
    int ptr1 = n-1;
    int ptr2 = n-1 ;
    int ans1 = 0;
    while (ptr1>=0 && ptr2>=1)
    {
        ptr1 = ptr2-1 ;
        int max1 = INT_MIN ;
        int sum1 = 0 ;
        while(ptr1>=0 &&colors[ptr1]==colors[ptr2])
        {
            max1 = max(max1 , neededTime[ptr1]);
            sum1+= neededTime[ptr1];
            ptr1-- ;
        }
        if(ptr1!=ptr2-1)
        {
            max1 = max(max1, neededTime[ptr2]);
            sum1+= neededTime[ptr2];
            ans1+=(sum1-max1);
            ptr2 = ptr1 ;
        }
        ptr2 = ptr1 ;
    }
    
    return ans1 ;

}
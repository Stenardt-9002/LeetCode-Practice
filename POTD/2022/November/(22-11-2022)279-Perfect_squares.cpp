
// https://leetcode.com/problems/perfect-squares/






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













    int numSquares(int n) 
    {
        static vector<int>countans = {0}    ;
        while(countans.size()<=n)
        {
            int cur_size = countans.size();
            int countsquares = 10 ;
            for(int i= 1;i*i<=cur_size;i++)
                countsquares = min(countsquares , countans[cur_size-i*i]+1);
            
            countans.push_back(countsquares) ;
        }
        return countans[n];
    }



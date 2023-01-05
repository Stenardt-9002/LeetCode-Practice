


// https://leetcode.com/problems/detect-capital/description/









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
    bool ascending(int col , int n , vector<string>array )
    {
        for(int i=0;i<n-1;++i)
            if(array[i][col]>array[i+1][col] )
                return false;
        return true;
    }
    int minDeletionSize(vector<string>& strs) 
    {
        int n = strs.size()    ;
        int m = strs[0].length() ;
        int ans = 0 ;
        for(int i=0;i<m;i++)
            ans+=(ascending(i ,n,strs));
        return m-ans ;
    }
};
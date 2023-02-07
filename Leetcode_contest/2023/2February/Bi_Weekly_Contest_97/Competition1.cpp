




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
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        set<int> se_hash ;
        for(auto ele:banned)    
            se_hash.insert(ele);
        int ans = 0 ;
        for (int i1 = 1; i1 <=n && maxSum>0; i1++)
            if(se_hash.find(i1)==se_hash.end() &&maxSum>=i1)
            {
                maxSum-=i1 ;
                ans++;
            }
            else if(maxSum<i1)
                maxSum = -1 ;
        
        return ans ;
        
    }
};
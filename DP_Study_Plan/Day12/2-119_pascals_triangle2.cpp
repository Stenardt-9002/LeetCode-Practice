










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
    vector<int> getRow(int rowIndex) 
    {
        vector<int>ans(rowIndex+1,1)    ;
        long long int temp = 1;
        long long int start = rowIndex ,down = 1;

        for(int i = 1;i<rowIndex;++i)
        {
            temp =  temp*(start--)/(down++);
            ans[i] = temp ;
        }
        return ans ;
    }
};
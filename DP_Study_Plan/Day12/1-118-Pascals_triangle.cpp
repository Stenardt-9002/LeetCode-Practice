
// https://leetcode.com/problems/pascals-triangle/description/









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
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>ans1 ;

        ans1.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int>temp1(i+1,1);
            for (int j = 1; j < i; j++)
                temp1[j] = ans1.back()[j-1]+ans1.back()[j];

            ans1.push_back(temp1)            ;
        }
        return ans1 ;
    }
};





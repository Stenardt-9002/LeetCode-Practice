// https://leetcode.com/problems/validate-stack-sequences/description/






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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i = 0 , j=0 ;    
        for(auto val : pushed)
        {
            pushed[i++] = val ; 
            while(i>0 && pushed[i-1]==popped[j])
                i-- , j++;
            
        }
        return i==0 ;
    }
};








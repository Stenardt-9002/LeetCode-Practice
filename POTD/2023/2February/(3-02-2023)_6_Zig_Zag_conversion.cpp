
// https://leetcode.com/problems/zigzag-conversion/description/













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
    string convert(string s, int numRows) 
    {
        if(numRows<2)    
            return s ;
        int length = s.length();
        vector<string> array(numRows);


        int row = 0 ;
        int step = 1;
        for (int i = 0; i < length; i++)
        {
            array[row].push_back(s[i]);
            if(row==0)
                step = 1;
            else if(row==numRows-1)
                step=-1;

            row+=step ;
        }
        s.clear();
        for (int j = 0; j < numRows; j++)
            s.append(array[j]);
        
        return s ;
    }
};














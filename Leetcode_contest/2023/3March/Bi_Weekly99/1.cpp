

// https://leetcode.com/problems/split-with-minimum-sum/
















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
    int splitNum(int num) 
    {
        vector<int>array;
        while(num!=0)
        {
            array.push_back(num%10);
            num/=10 ;
        }
        sort(array.begin(),array.end(),greater<int>());
        int n = array.size();
        int ans = 0 ;
        int power = 0 ;
        for(int i = 0 ; i<n/2; i++)
        {
            ans+=((array[2*i]+array[2*i+1])*pow(10,power));
            power++ ;
        }
        if(n%2)
            ans+=(array[n-1]*pow(10,power));
        return ans ;
            
    }
};





































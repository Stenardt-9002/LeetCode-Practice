// https://leetcode.com/problems/beautiful-arrangement/





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




int recursive(set<int> s1 , int size)
{
    int ans1 = 0 ;
    if (size==0)
        return 1 ; 
    set<int> copy = s1;
    for(auto ele : s1)
        if(ele%size ==0 || size%ele==0)
        {
            int cur = ele ;
            copy.erase(copy.find(cur));
            ans1+=recursive(copy,size-1);
            copy.insert(cur);
        }

    return ans1 ;    
}












class Solution {
public:
    int countArrangement(int n) 
    {
        set<int> s1 ;
        for (int i = 0; i < n; i++)
            s1.insert(i+1);

        return recursive(s1,n);
            
    }
};
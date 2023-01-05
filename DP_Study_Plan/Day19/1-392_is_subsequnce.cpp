// https://leetcode.com/study-plan/dynamic-programming/?progress=x0y0n9pc
















#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int ptr1 = 0 ,ptr2 = 0;    
        int n = s.length() ;
        int m = t.length() ;
        while(ptr1<n && ptr2<m)
            if(s[ptr1]==t[ptr2++])
                ptr1++;
        return ptr1==n;
    }
};





































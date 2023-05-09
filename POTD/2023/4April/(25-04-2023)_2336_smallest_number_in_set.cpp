
// https://leetcode.com/problems/smallest-number-in-infinite-set/






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




class SmallestInfiniteSet {
public:
    set<int> s1 ; 
    SmallestInfiniteSet() 
    {
        for(int i=1 ; i<=1000 ; i++)
            s1.insert(i);
    }
    
    int popSmallest() 
    {
        int ans = *(s1.begin());
        s1.erase(s1.begin());
        return ans ;    
    }
    
    void addBack(int num) {
        s1.insert(num);
    }
};

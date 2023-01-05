
// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=study-plan&id=graph-i




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
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity>targetCapacity)
            return false ;
        if (targetCapacity==0)
            return true ;

        return targetCapacity%(__gcd(jug1Capacity , jug2Capacity))==0;
        
    }
};
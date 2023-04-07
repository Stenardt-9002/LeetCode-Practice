
// https://leetcode.com/problems/boats-to-save-people/










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





// two pointer 



class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int n = people.size();
        int first = 0 ; 
        int size = n-1 ;
        sort(people.begin(),people.end())    ;
        int ans = 0 ; 
        while(first<=size)
        {
            if(first !=size && people[size]+people[first]<=limit)
                first++ , size-- ;
            else if(people[size]<=limit)
                size-- ;
            ans++;
        }
        return ans ; 
    }
};



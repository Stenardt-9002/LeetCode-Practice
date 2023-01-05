// https://leetcode.com/problems/insert-delete-getrandom-o1/














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





class RandomizedSet {
public:
    set<int> s1 ;
    RandomizedSet() {
        s1 = {};
    }
    
    bool insert(int val) {
        if(s1.find(val)!=s1.end())
            return false ;

        s1.insert(val);
        return true ;
    }
    
    bool remove(int val) 
    {
        if(s1.find(val)==s1.end())
            return false ;
            
        s1.erase(val);
        return true ;
            
    }
    
    int getRandom() 
    {
        int suze = s1.size()    ;
        int index = rand()%suze ;
        auto it = s1.begin();
        while(index--)
            it++ ;
        return *it ;
    }
};






























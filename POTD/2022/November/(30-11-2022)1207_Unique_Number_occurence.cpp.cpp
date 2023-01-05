    
    // https://leetcode.com/problems/unique-number-of-occurrences/













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








    bool uniqueOccurrences(vector<int>& arr) 
    {
        int i =0 , j = 0 , n= arr.size();
        if(n==1)
            return true ;
        sort(arr.begin() , arr.end())    ;
        set<int> frequency ;
        int count = 0 ;
        
        while(i<n)
        {
            while(j<n && arr[j]==arr[i])
                j++ ;
            if(frequency.find(j-i)!=frequency.end())
                    return false ;
            frequency.insert(j-i);
            i = j ;
        }
        return true ;
    }

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        sort(tokens.begin(),tokens.end());
        int ans1 = 0 , points = 0 ;
        int i1 = 0 , j1 = tokens.size()-1;    
        bool contloop= true ;
        while (i1<=j1 && contloop )
            if(power>=tokens[i1])
                power-=tokens[i1++] , ans1 = max(ans1 , ++points) ;
            else if(points>0)
                points-- , power+=tokens[j1--];
            else 
                contloop = false ;
        

        return ans1 ;
    }
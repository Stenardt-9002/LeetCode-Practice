// https://leetcode.com/problems/push-dominoes/




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

const long long int mod2 =  1e18 ;



string pushDominoes(string dominoes) 
{
    dominoes = 'L'+dominoes+'R';
    int n = dominoes.size() , i1=0,j1 =1;

    string ans1 = "";
    for(i1 = 0 , j1=1 ; j1<n ; j1++)
    {
        if(dominoes[j1]=='.')
            continue ;
        int mid = j1-i1-1 ;
        if(i1>0)
            ans1+=dominoes[i1];
        if(dominoes[i1]==dominoes[j1] )
            ans1+=string(mid ,dominoes[i1]);

        else if(dominoes[i1]=='L' && dominoes[j1]=='R')
            ans1+=string(mid ,'.');

        else    
            ans1+=string(mid/2 ,'R' )+string(mid%2 , '.')+ string(mid/2 , 'L')        ;
        
        i1 =j1 ;
    }
    
    return ans1 ;

}



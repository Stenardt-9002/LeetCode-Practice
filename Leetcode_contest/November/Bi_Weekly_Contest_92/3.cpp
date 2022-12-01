




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


int bestClosingTime(string customers) 
{
    int ans_index = 0 ;
    ll min_penalty_val = 0;
    ll penalty_val =  0 ;
    int n = customers.length();
    for (int i1 = 0; customers[i1]; i1++)
        if(customers[i1]=='Y')
            penalty_val++ ;


    min_penalty_val = penalty_val ;
    for (int i1 = 0; customers[i1]; i1++)
    {
        if(customers[i1]=='Y')
            penalty_val--;
        else 
            penalty_val++;
        
        if(min_penalty_val>penalty_val)
        {
            ans_index = i1+1 ;
            min_penalty_val = penalty_val ;
        }
    }
    

    return ans_index ;

}



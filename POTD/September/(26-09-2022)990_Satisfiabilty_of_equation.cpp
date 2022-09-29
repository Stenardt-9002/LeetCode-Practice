// https://leetcode.com/problems/satisfiability-of-equality-equations/





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



int find_fuc(int x , vector<int> &union_array)
{
    if(x!=union_array[x])
        union_array[x] = find_fuc(union_array[x] ,union_array);
    return union_array[x] ;
}



bool equationsPossible(vector<string>& equations) 
{
    vector<int> union_array(26,0);
    for (int i1 = 0; i1 < 26; i1++)
        union_array[i1] = i1;

    for(auto e1 : equations)
        if(e1[1]=='=')
            union_array[find_fuc(e1[0]-'a' , union_array)] = find_fuc(e1[3]-'a' , union_array);


    for(auto e1 : equations)
        if(e1[1]=='!' && find_fuc(e1[0]-'a' ,union_array)==find_fuc(e1[3]-'a' ,union_array) )
            return false ;

    return true ;
        
}



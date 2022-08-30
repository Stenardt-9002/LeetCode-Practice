// https://leetcode.com/problems/combination-sum-iv/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
{
    return ceil(log(buckets)/log(minutesToTest/minutesToDie +1));    
}
int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n,a,b;
    testcase=1 ;
    while (testcase--)
    {
        cin>>n>>a>>b ;

    }
    return 0 ;
}






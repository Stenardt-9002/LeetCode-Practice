// https://leetcode.com/problems/reordered-power-of-2/






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



bool reorderedPowerOf2(int n) 
{
    // int checkifpower = 1<<30 ;

    string allpossible_int = "";
    while(n!=0)
    {
        int val = n%10 ;
        n/=10 ;
        char val1 = val+'0';
        allpossible_int +=val1 ; 
    }
    sort(allpossible_int.begin() , allpossible_int.end()) ;
    for (int pow1 = 0; pow1 < 31; pow1++)
    {
        int vin = 1<<pow1 ;
        string comp = to_string(vin);
        sort(comp.begin() , comp.end());
        if(comp == allpossible_int)
            return true ;
    }
    return false ;

}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    int intup ;
    while (testcase--)
    {
        cin>>intup ;
        // cout<<reorderedPowerOf2(intup)<<endl;
        reorderedPowerOf2(intup);
        cout<<endl;

    }
    return 0 ;
}




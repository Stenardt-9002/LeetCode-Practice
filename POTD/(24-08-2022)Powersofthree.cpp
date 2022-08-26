// https://leetcode.com/problems/power-of-three/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




// bool isPowerOfThree(int n) {
//     if(n<=0)
//     return false ;
//     int logbase = log10(n)/log10(3);
//     if(pow(3,logbase)==n)
//         return true ;
//     return false ;
// }


// Big FuckoFF excellent method 
bool isPowerOfThree(int n) 
{
    int power3_19 = 1162261467 ;// #620 is larger than int 
    return (n>0 && power3_19%n==0);
    //this method worksa for all prime number 2,3,5,7,11
}


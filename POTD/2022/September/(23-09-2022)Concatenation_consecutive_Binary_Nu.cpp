// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/





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

// string binary_increment(string input  )
// {
//     string ans1 = "";
//     int carry = 1 ;
//     int n = input.size() ;
//     for (int i1 = n-1; i1 >=0; i1--)
//     {
//         if(input[i1]=='0' && carry ==1 )
//         {
//             ans1="1"+ans1;
//             carry = 0 ;

//         }
//         else if(input[i1]=='0' && carry ==0 )
//         {
//             ans1="0"+ans1;
//             carry = 0 ;
//         }
//         else if(input[i1]=='1' && carry ==0 )
//         {
//             ans1="1"+ans1;
//             carry = 0 ;
//         }
//         else if(input[i1]=='1' && carry ==1 )
//         {
//             ans1="0"+ans1;
//             carry = 1 ;
//         }
//     }
//     if(carry==1)
//         ans1 = 
    

// }
int get_digits(int input  )
{
    // int digits = 
    return floor(log2(input))+1;

}


int concatenatedBinary(int n) 
{
    ll sum1 = 1 ;
    for(int i1 = 2 ; i1 <=n ; i1++)
    {
        int length1 = floor(log2(i1))+1;
        sum1 = sum1*(1<<length1)+i1 ;
        sum1%=MOD1;
    }
    return sum1 ;
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        cout<<concatenatedBinary( n)<<endl;
    }
    return 0 ;
}



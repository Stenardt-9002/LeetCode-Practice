// https://leetcode.com/problems/string-compression-ii/



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

int length_nu(int x)
{
    if(x>=100)
        return 3 ;
    else if (x<100&&x>=10)
        return 2 ;
    else if(x<10&&x>1)   
        return 1 ;
    return 0 ;
}
int recursive_func(int left , int k ,string new_construct_string,vector<vector<int>>&dp1 )
{
    if(k<0)
        return 135 ;
    int n = new_construct_string.length();
    if(left>=n|| n-left<=k)
        return 0;
    // cout<<s<<endl ;
    if(dp1[left][k]!=-1)
        return dp1[left][k];

    dp1[left][k] = 135 ;
    vector<int> hash_letter(26,0);
    int i1 = 0 ,number1 = 0;
    for(i1=left ,number1 = 0 ;i1<n;i1++)
    {
        number1 = max(number1 , ++hash_letter[new_construct_string[i1]-'a']);
        dp1[left][k] = min(dp1[left][k] , (1+length_nu(number1)+recursive_func(i1+1,k-(i1-left+1-number1) ,new_construct_string ,dp1 ) ));
    }



    return dp1[left][k] ;
}


int getLengthOfOptimalCompression(string s, int k) 
{
    //preprocess 
    vector<vector<int>> dp1(105,vector<int>(105,-1));
    int n = s.size();
    string new_construct_string = s ;
    return recursive_func(0 ,k ,new_construct_string,dp1 );
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    
    getLengthOfOptimalCompression(s,3);
    return 0;
}


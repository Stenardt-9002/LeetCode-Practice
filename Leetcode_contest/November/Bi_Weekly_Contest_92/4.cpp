



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

// int recursive_func(string s , int start , int end , int length,vector<vector<vector<int>>> &dp1,vector<set<int>> hash_1)
// {
//     if(dp1[start][end][length]!=-1)
//         return dp1[start][end][length] ;
//     if(length<0)
//         return 0 ;
//     if(length ==1 )
//         return end-start+1 ;
//     if(end==start)
//         return 1 ;
//     else if(end<start)
//         return 0 ;
//     int ans1 = 0 ;
//     // for (int i1 = start; i1 < end-length+2; i1++)
//     //     for (int j1 = i1+length-1; j1 <end+1 ; j1++)
//     //         if(s[i1]==s[j1])
//     //         {
//     //             ans1+=recursive_func(s , i1+1 , j1-1 ,length-2,dp1,hash_1);
//     //             ans1 = ans1%mod1 ;
//     //         }
//     for (int i1 = start; i1 < end-length+2; i1++)
//     {
//         auto iterator = hash_1[s[i1]-'0'].lower_bound(i1+length-1);
//         for(auto it = iterator;it!=hash_1[s[i1]-'0'].end();it++)
//         {

//                 ans1+=recursive_func(s , i1+1 , *it-1 ,length-2,dp1,hash_1);
//                 ans1 = ans1%mod1 ;
//         }
//     }

        
//     dp1[start][end][length] = ans1%mod1 ;
//     return dp1[start][end][length] ;
// }


// int countPalindromes(string s) 
// {
//     int ans1 ;
//     int n = s.length();
//     if(n<5)
//         return 0 ;
    
//     //hash string 
//     vector<set<int>> hash_1(10);
//     for(int i =0 ;s[i];i++)
//         hash_1[s[i]-'0'].insert(i);


//     vector<vector<vector<int>>>dp1(n ,vector<vector<int>>(n,vector<int>(6,-1)));
//     ans1 = recursive_func(s , 0 , n-1 , 5,dp1,hash_1);
//     return ans1 ;
// }



int recursive_func(string s , int start , int end , int length,vector<vector<vector<int>>> &dp1,vector<set<int>> hash_1)
{
    if(dp1[start][end][length]!=-1)
        return dp1[start][end][length] ;
    if(length<0)
        return 0 ;
    if(length ==1 )
        return end-start+1 ;
    if(end==start)
        return 1 ;
    else if(end<start)
        return 0 ;
    int ans1 = 0 ;
    for (int i1 = start; i1 < end-length+2; i1++)
        for (int j1 = i1+length-1; j1 <end+1 ; j1++)
            if(s[i1]==s[j1])
            {
                ans1+=recursive_func(s , i1+1 , j1-1 ,length-2,dp1,hash_1);
                ans1 = ans1%mod1 ;
            }
            else 
            {
                ans1+=recursive_func(s , i1+1 , j1 ,length-1,dp1,hash_1);
                ans1 = ans1%mod1 ;

                ans1+=recursive_func(s , i1 , j1-1 ,length-1,dp1,hash_1);
                ans1 = ans1%mod1 ;

                ans1-=recursive_func(s , i1+1 , j1-1 ,length-2,dp1,hash_1);
                ans1 = ans1%mod1 ;




            }


        
    dp1[start][end][length] = ans1%mod1 ;
    return dp1[start][end][length] ;
}


int countPalindromes(string s) 
{
    int ans1 ;
    int n = s.length();
    if(n<5)
        return 0 ;
    
    //hash string 
    vector<set<int>> hash_1(10);
    for(int i =0 ;s[i];i++)
        hash_1[s[i]-'0'].insert(i);


    vector<vector<vector<int>>>dp1(n ,vector<vector<int>>(n,vector<int>(6,-1)));
    ans1 = recursive_func(s , 0 , n-1 , 5,dp1,hash_1);
    return ans1 ;
}

int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {

    }


    return 0;
}





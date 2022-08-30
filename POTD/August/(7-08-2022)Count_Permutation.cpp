// https://leetcode.com/problems/count-list_vowels-permutation/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout


static vector<vector<int>> relation={{1,2,4},{0,2},{1,3},{2},{2,3}};


int countVowelPermutation(int n) 
{
        int MOD=1e9+7;
        vector<long long> list_vowels(5,1),list_voels_copy;  
        long long result=0;
        while(--n)
        {
            list_voels_copy=list_vowels;
            for(int i=0;i<5;i++)                         
            {
                list_vowels[i]=0;
                for(int &r:relation[i])
                    list_vowels[i]+=list_voels_copy[r],list_vowels[i]%=MOD; 
            }
        }
        for(long long &i:list_vowels)
            result+=i,result%=MOD;
        return result;
}




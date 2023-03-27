// https://leetcode.com/problems/can-place-flowers/description/
















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










class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int clear = 0 ;
        int size = flowerbed.size();
        if(size<=2)
        {
            if(size==1)
                return flowerbed[0]+n<=1;
            
            if(flowerbed[0]+flowerbed[1]==2)
                return n==0 ;
            return flowerbed[0]+flowerbed[1]+n<2;
        }
        if(flowerbed[0]==0 &&flowerbed[1]==0 )
        {
           flowerbed[0] = 1; 
            clear++ ;
        }
        for(int i = 1;i<size-1;i++)
            if(flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0)
                {
                    clear++ ;
                    flowerbed[i]=1;
                }
        
        if(flowerbed[size-2]==0 &&flowerbed[size-1]==0 )
        {
            flowerbed[size-1] = 1; 
            clear++ ;
        }
        return clear>=n ;
    }
};





























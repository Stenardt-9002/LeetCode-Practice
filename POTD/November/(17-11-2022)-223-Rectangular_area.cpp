// https://leetcode.com/problems/rectangle-area/




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


    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
            int xdis = min(ax2,bx2)-max(ax1,bx1);
            int ydis = min(ay2,by2)-max(ay1,by1);
            int commonarea = 0;        
            if(xdis<=0||ydis<=0)
                commonarea = 0;
            else 
                commonarea = xdis*ydis ;
        
            return ((ax2-ax1)*(ay2-ay1))+((bx2-bx1)*(by2-by1))-commonarea;
        
    }




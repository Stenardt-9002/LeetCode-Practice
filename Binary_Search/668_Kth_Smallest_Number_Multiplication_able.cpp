// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

typedef  long long int lld;


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int count_v(int m , int n ,int mid)
{
    int count = 0;
    for(int i = 0 ;i<m ; i++)
        count+=min(mid/(i+1) , n);
    return count ; 
}


class Solution 
{
public:
    int findKthNumber(int m, int n, int k) 
    {
        int low = 1 , high = n*m ;
        int mid , ans ; 
        while(low<=high)    
        {
            mid = low+(high-low)/2;
            if(count_v(m , n ,mid)<k)
                low = mid+1 ;
            else
            {
                high = mid-1 ;
                ans = mid ;
            }
        }
        return ans ;
    }
};

































// https://leetcode.com/problems/find-k-closest-elements/


// https://leetcode.com/problems/push-dominoes/




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

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
        multiset<pair<int,int>> s1 ;
        int n = arr.size();
        int i1 = 0 ;
        for (i1= 0; i1 < n; i1++)
            s1.insert({abs(arr[i1]-x),i1});

        vector<int> ans1 ;
        i1 = 0 ;
        for(auto x = s1.begin() ;i1++<k&& x!=s1.end();x++)
            ans1.push_back(arr[x->second]);
        sort(ans1.begin(),ans1.end());
        return ans1 ;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
        int n = arr.size();
        int left = 0 ;
        int right = n-k ;
    while(left<right)
    {
        int mid = (left+right)>>1 ;
        if(x-arr[mid]>arr[mid+k]-x)
            left = mid+1 ;
        else 
            right = mid ;
    }
    return vector<int>(arr.begin()+left , arr.begin()+left+k);
    
}
// https://leetcode.com/problems/sum-of-subarray-minimums/








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









int sumSubarrayMins(vector<int>& arr) 
{
    int n = arr.size();
    long long int ans1 = 0 ;
    int min_val = INT_MAX ;
    for (int i1 = 0; i1 < n; i1++)
    {
        min_val = arr[i1];
        for (int j1 = i1; j1 < n; j1++)
        {
            min_val = min(min_val,arr[j1]);
            ans1+=min_val ;
            ans1 = ans1%mod1 ;
        }
        
    }
    return ans1%mod1 ;
    
}


int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> left(n,-1), right(n,n);
        // for every i find the Next smaller element to left and right
        
        // Left
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        // Right
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        
        // for(int i=0; i<n; i++) cout << left[i] << " : " << right[i] << endl;
        
        // for each i, contribution is (Left * Right) * Element 
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }





int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left_small_ele(n,-1), right_larger_ele(n,n);
        
        stack<int> s1;
        for(int i=0; i<n; i++)
        {
            while(s1.size() && arr[i] < arr[s1.top()]) 
                s1.pop();
            if(s1.size()) 
                left_small_ele[i] = i - s1.top();
            else 
                left_small_ele[i] = i+1;
            s1.push(i);
        }
        
        while(s1.size()) 
            s1.pop();
        
        for(int i=n-1; i>=0; i--)
        {
            while(s1.size() && arr[i] <= arr[s1.top()]) 
                s1.pop();
            if(s1.size()) 
                right_larger_ele[i] = s1.top() - i;
            else 
                right_larger_ele[i] = n - i;
            s1.push(i);
        }
        

        int ans1 = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left_small_ele[i]*right_larger_ele[i])%mod1;
            prod = (prod*arr[i])%mod1;
            ans1 = (ans1 + prod)%mod1;
        }
        
        return ans1%mod1;
    }







// https://leetcode.com/problems/sort-an-array/
















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


void heapify(vector<int> &arr , int size, int src)
{
    int largest = src ;
    int left_c = 2*src+1 ;
    int rightc = 2*src+2 ;
    if(left_c<size && arr[largest]<arr[left_c])
        largest = left_c ;
    if(rightc<size && arr[largest]<arr[rightc])
        largest = rightc ;

    if(largest!=src)
    {
        swap(arr[src] , arr[largest]);
        heapify(arr,size , largest);
    }
    
}


void _heap_sort(vector<int>&arr , int sdize)
{
    for (int i = sdize/2 -1; i>=0; i--)
        heapify(arr,sdize , i);
    //O(n)
    
    for (int i = sdize - 1; i >= 0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr, i , 0);
    }
    


    
}

class Solution {
public:



    vector<int> sortArray(vector<int>& nums) 
    {
        int n= nums.size();
        _heap_sort(nums ,n );
        return nums ;
    }
};









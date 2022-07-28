// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

vector<int> searchRange(vector<int>& nums, int target) 
{
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
        
        if(low == nums.end() || *low != target)    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};

}
vector<int> searchRange(vector<int>& nums, int target) 
{
    int n = nums.size() ;
    if(n==0||(n==1 && target!=nums[0]))
        return {-1,-1} ;
    
    if(n==1 && target==nums[0])
        return {0,0} ;
    int start = 0 , end = n ;
    int mid ;
    int ans1 =-1; 
    while(start<=end)
    {

        mid = start+((end-start+1)>>1) ;
        if(nums[mid]>target)
            end = mid-1 ;
        else if(nums[mid]<target)
            start = mid+1 ;
        else 
            {
                ans1 = mid;
                end = mid-1 ;
            }
    }

    start = 0 , end = n ;
    if(ans1== -1)
        return {-1,-1};
    int ans2 =-1; 
    while(start<=end)
    {

        mid = start+((end-start+1)>>1) ;
        if(nums[mid]>target)
            end = mid-1 ;
        else if(nums[mid]<target)
            start = mid+1 ;
        else 
            {
                ans2 = mid;
                start = mid+1 ;
            }
    }
    return {ans1,ans2} ;
    // return {-1,-1};


}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int testcase ; cin>>testcase;
    while(testcase--)
    {
        int n,tartget ;
        cin>>n>>tartget;
        vector<int> inut1(n,0) ;
        for (int i1 = 0; i1 < n; i1++)
            cin>>inut1[i1];
        vector<int> output = searchRange(inut1,tartget);
        cout<<endl ;
        for (auto i : output)
            cout<<" "<<i ;
            
    }   
    return 0 ;
}





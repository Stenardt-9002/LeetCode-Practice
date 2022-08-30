// https://leetcode.com/problems/count-list_vowels-permutation/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> dp1(n,1);
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = i1+1; j1 < n; j1++)
            if(nums[i1]<nums[j1])
                dp1[j1] =  max(dp1[i1]+1 , dp1[j1]);
    
    return *max_element(dp1.begin(),dp1.end());
}

int main(int argc, char const *argv[])
{
    
    return 0;
}



// int main(int argc, char const *argv[])
// {
//     fastIO

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output1.txt","w",stdout);
//     #endif 


//     int testcase ;
//     long long int n,a,b;
//     testcase=1 ;
//     while (testcase--)
//     {
//         cin>>n>>a>>b ;

//     }
//     return 0 ;
// }




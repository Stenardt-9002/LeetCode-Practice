// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/





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


void recursive_func(int start , vector<string> arr , string current_string , int &ans1)
{
    int n = arr.size();
    if(start>=n)
        return ;
    //include_start and see
    vector<int> hash_1(26,0);
    for(auto c : current_string+arr[start])
        if(hash_1[c-'a']++>0)
            return ;
    
    current_string+=arr[start];
    int length1 = current_string.length();
    ans1 = max(ans1,length1);
    for (int i1 = start+1; i1 < n; i1++)
        recursive_func(i1,arr,current_string,ans1)        ;

}


int maxLength(vector<string>& arr) 
{
    int ans1 = 0 ;
    string current_string = "";
    for (int i1 = 0; i1 < arr.size(); i1++)
        recursive_func(i1,arr,current_string , ans1);


    return ans1 ;
}







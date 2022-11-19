// https://leetcode.com/problems/palindrome-pairs/











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





bool checkifpallindrome(string word1 , int start , int end)
{
    while(start<=end && word1[start]==word1[end])
        start++ , end-- ;

    return start>=end ;
}


vector<vector<int>> palindromePairs(vector<string>& words) 
{
    int i1 ,n = words.size();
    unordered_map<string,int> map1 ;
    vector<vector<int>> ans1 ;

    for (i1 = 0; i1 < n; i1++)
    {
        string key = words[i1];
        reverse(key.begin(),key.end());
        map1[key] = i1 ;
    }
    
    if(map1.find("")!=map1.end())
    {
        for (i1 = 0; i1 < n; i1++)
        {
            if(i1==map1[""])
                continue ;
            if(checkifpallindrome(words[i1],0,words[i1].size()-1) )
                ans1.push_back({map1[""],i1});
        }
    }

    int j1 ;
    string left_str , right_str ;
    for (i1 = 0; i1 < n; i1++)
    {
        for ( j1 = 0; j1 < words[i1].size(); j1++)
        {
            left_str = words[i1].substr(0,j1);
            right_str = words[i1].substr(j1,words[i1].size()-j1);

            if(map1.find(left_str)!=map1.end() && checkifpallindrome(right_str,0,right_str.size()-1) && map1[left_str]!=i1)
                ans1.push_back({i1,map1[left_str]});

            if(map1.find(right_str)!=map1.end() && checkifpallindrome(left_str,0,left_str.size()-1) && map1[right_str]!=i1)
                ans1.push_back({map1[right_str],i1});
            
        }
        
    }
    
    return ans1 ;

}









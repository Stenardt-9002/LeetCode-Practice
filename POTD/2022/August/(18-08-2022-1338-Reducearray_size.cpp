// https://leetcode.com/problems/first-unique-character-in-a-string/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



bool compare_fuc(pair<int,int> a1, pair<int,int> b1)
{
    return a1.second>b1.second ;
}


int minSetSize(vector<int>& arr) 
{
    int n = arr.size();
    unordered_map<int,int> freq_count ;
    for(auto x : arr)    
        if(freq_count.find(x)==freq_count.end())
            freq_count[x] = 1;
        else 
            freq_count[x]++;

    // sort(freq_count.begin(),freq_count.end(),comapre_fuc);

    vector<pair<int,int>> hash_map ;
    for(auto x : freq_count)
        hash_map.push_back({x.first , x.second});

    sort(hash_map.begin(),hash_map.end(),compare_fuc);

    int nas1 = 0 ;
    int count_yet = 0;
    for(auto x: hash_map)
        if(count_yet<n/2)
            count_yet+=x.second , nas1++;


    return nas1 ;


}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    string s ;
    while (testcase--)
    {
        cin>>n;
        vector<int> words(n) ;
        for(auto &chr : words)
            cin>>chr;
        cout<<minSetSize(words)<<endl;
    }
    return 0 ;
}



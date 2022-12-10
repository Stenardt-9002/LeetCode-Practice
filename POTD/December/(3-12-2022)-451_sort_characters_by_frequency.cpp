// https://leetcode.com/problems/sort-characters-by-frequency/












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




bool comparator(pair<int,char> a , pair<int,char> b)
{
    return a.first>b.first ;
}







// string frequencySort(string s) 
// {
//     vector<int>hash_char(52,0)    ;
//     for(auto c : s)
//         if(c>='a' && c<='z')
//             hash_char[c-'a'+26]++ ;
//         else 
//             hash_char[c-'A']++ ;


//     vector<pair<int, char > >data_container ;
//     for (int i = 0; i < 26; i++)
//         data_container.push_back({hash_char[i] , i+'A'});
//     for (int i = 26; i < 52; i++)
//         data_container.push_back({hash_char[i] , i+'a'-26});


//     sort(data_container.begin() , data_container.end() , comparator);
//     string ans1 = "";

//     for (int i = 0; i < 52; i++)
//         while(data_container[i].first--)
//         ans1+=data_container[i].second ;
    
//     return ans1 ;
// }



string frequencySort(string s) 
{
    vector<int>hash_char(62,0)    ;
    for(auto c : s)
        if(c>='a' && c<='z')
            hash_char[c-'a'+26]++ ;
        else if(c>='A' && c<='Z')
            hash_char[c-'A']++ ;
        else 
            hash_char[c-'0'+52]++ ;



    vector<pair<int, char > >data_container ;
    for (int i = 0; i < 26; i++)
        data_container.push_back({hash_char[i] , i+'A'});
    for (int i = 26; i < 52; i++)
        data_container.push_back({hash_char[i] , i+'a'-26});
    for (int i = 52; i < 62; i++)
        data_container.push_back({hash_char[i] , i+'0'-52});


    sort(data_container.begin() , data_container.end() , comparator);
    string ans1 = "";

    for (int i = 0; i < 62; i++)
        while(data_container[i].first--)
        ans1+=data_container[i].second ;
    
    return ans1 ;
}













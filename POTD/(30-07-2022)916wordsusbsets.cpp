// https://leetcode.com/problems/word-subsets/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


// bool ok_check(string insert , vector<string>& words2) 
// {
//     //preprocess input 
//     vector<int>chr_hash(26,0) ;
//     int n = insert.size() ;
//     for (int i1 = 0; i1 < n; i1++)
//         chr_hash[insert[i1]-'a']++;
//     for (auto singleowrd : words2)
//     {
//         vector<int>char_hash = chr_hash ;
//         for (auto letter:singleowrd)
//             if(--char_hash[letter-'a']<0)
//                 return false ;
//     }
//     return true ;
// }


// vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
// {
//     int n = words1.size();
//     vector<string>ans1 ;
//     for (int i1 = 0; i1 < n; i1++)
//         if(ok_check(words1[i1],words2))
//             ans1.push_back(words1[i1]);


//     return ans1 ;

// }




vector<int> ok_check(string insert )
{
    //preprocess input 
    vector<int>chr_hash(26,0) ;
    for (auto letter:insert)
        chr_hash[letter-'a']++ ;
    
    return chr_hash ;
}


vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
{
    int m = words2.size();
    vector<string>ans1 ;
    vector<int> hash_setstring1(26,0),tmp1(26) ;
    int i1 ;
    for (i1 = 0; i1 < m; i1++)
    {
        tmp1 = ok_check(words2[i1]);
        for(int j = 0 ; j<26 ; j++)
            hash_setstring1[j] = max(hash_setstring1[j],tmp1[j]);
    }
    for(auto eachword:words1)
    {
        tmp1 = ok_check(eachword);
        for ( i1 = 0; i1 < 26; i1++)
            if(tmp1[i1]<hash_setstring1[i1])
                break ;
        if(i1==26)
            ans1.push_back(eachword);
        
    }
    return ans1 ;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n ,m;
    cin>>n>>m ;
    vector<string> intup1 ;
    vector<string> intup2 ;

    string temp1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>temp1 ;
        intup1.push_back(temp1);
    }
    for (int i1 = 0; i1 < m; i1++)
    {
        cin>>temp1 ;
        intup2.push_back(temp1);
    }

    vector<string> ans1 = wordSubsets(intup1 , intup2);

    cout<<endl ;
    for(auto x: ans1)
        cout<<" "<<x;
    // for(auto x: intup2)
    //     cout<<" "<<x;
    // cout<<endl<<ok_check("facebook",intup2)  ;
    return 0 ;
}
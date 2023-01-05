// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1



bool func_check(string a , string b)
{
    if(a.length()!=b.length())
        return false ;

    unordered_map<char,char> hash_mao1 ;
    unordered_map<char,char> hash_mao2 ;

    for (int i1 = 0; i1 < a.length(); i1++)
    {
        if((hash_mao1.find(a[i1])==hash_mao1.end())&& (hash_mao2.find(b[i1])==hash_mao2.end()))
            hash_mao1[a[i1]] = b[i1] , hash_mao2[b[i1]] = a[i1];

        else if((hash_mao1.find(a[i1])==hash_mao1.end())|| (hash_mao2.find(b[i1])==hash_mao2.end()))
            return false ;
        
        else {
            if(!((hash_mao1[a[i1]]==b[i1])&&(hash_mao2[b[i1]]=a[i1]) ))
                return false ;
        }

    }
    return true ;
}


vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
{

    vector<string> ans1 ;
    for (auto str1 : words)
        if(func_check(str1,pattern))
            ans1.push_back(str1);
    
    return ans1 ;
}



int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n ;
    cin>>n ;
    string pattern1 ; cin>>pattern1 ;    
    vector<string> intup ;
    string temp1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>temp1 ;
        intup.push_back(temp1);
    }

    vector<string> ans1 = findAndReplacePattern(intup , pattern1);

    cout<<endl ;
    for(auto x: ans1)
        cout<<" "<<x;
    
            
    return 0 ;
}




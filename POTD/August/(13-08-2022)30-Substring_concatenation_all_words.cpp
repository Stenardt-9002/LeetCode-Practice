// https://leetcode.com/problems/substring-with-concatenation-of-all-words/





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




vector<int> findSubstring(string s, vector<string>& words) 
{
    int n = s.size();
    if(n==0)
        return {-1};
    unordered_map<string,int> ordiginal ;
    unordered_map<string,int> map1 ;

    vector<int> ans1={} ;
    int get_length = words[0].size()   ;
    int vectorsize = words.size();

    // cout<<"DEBUG 1 "<<s<<" "<<words[0]<<endl;

    //preprocess words 
    for(auto str:words)
        if(ordiginal.find(str)==ordiginal.end())
            ordiginal[str] =  1;
        else 
            ordiginal[str]++;


    for (int startidx = 0; startidx <=n-(vectorsize*get_length) ; startidx++)
    {
        map1 = ordiginal;
        bool breakflag = true;
        for (int j1 = startidx; j1 <= startidx+((vectorsize-1)*get_length) && breakflag==true; j1+=get_length)
        {
            string first = s.substr(j1,get_length);
            if(map1.find(first)==map1.end() || map1[first]==0)
                breakflag = false ;
            else 
                map1[first]-- ;
        }
        if(breakflag)
        ans1.push_back(startidx);
    }
    return ans1 ;
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    string s ;
    while (testcase--)
    {
        cin>>n;
        vector<string> words(n) ;
        for(auto &chr : words)
            cin>>chr;
        cin>>s ;
        vector<int> input = findSubstring(s,words);
        cout<<endl;
        for(auto x : input)
            cout<<x<<" ";
    }
    return 0 ;
}













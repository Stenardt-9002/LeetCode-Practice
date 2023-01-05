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



// bool checkifpallindrome(string word1 , string word2)
// {
//     string news = word1+word2 ;
//     int i1 = 0 ; int j1 = news.size()-1 ;
//     while(i1<=j1 && news[i1]==news[j1])
//         i1++ , j1-- ;

//     return i1>=j1 ;


// }

// vector<vector<int>> palindromePairs(vector<string>& words) 
// {
//     int n = words.size();
//     vector<vector<int>> ans1 ;
//     for (int i1 = 0; i1 < n; i1++)
//         for (int j1 = 0; j1 < n; j1++)
//             if(i1!=j1 && checkifpallindrome(words[i1],words[j1]))
//                 ans1.push_back({i1,j1});
    
//     return ans1 ;
// }



































bool checkifpallindrome(string word1 , int start , int end)
{
    
    int i1 = start ; int j1 = end;
    while(i1<=j1 && word1[i1]==word1[j1])
        i1++ , j1-- ;

    return i1>=j1 ;


}

vector<vector<int>> palindromePairs(vector<string>& words) 
{
    int n = words.size();
    vector<vector<int>> ans1 ;
    unordered_map<string , int > sdict ;
    for (int i1 = 0; i1 < n; i1++)
        sdict[words[i1]] = i1 ;

    


    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 <=words[i1].length(); j1++)
        {
            if(checkifpallindrome(words[i1] , j1 , words[i1].size()-1))
            {
                string suffix = words[i1].substr(0,j1);
                reverse(suffix.begin(),suffix.end());
                if(sdict.find(suffix)!=sdict.end() && i1!=sdict[suffix])
                    ans1.push_back({i1,sdict[suffix]});
            }

            if(j1>0 && checkifpallindrome(words[i1] , 0 , j1-1))
            {
                string prefix = words[i1].substr(j1);
                reverse(prefix.begin(),prefix.end());
                if(sdict.find(prefix)!=sdict.end() && sdict[prefix]!=i1)
                    ans1.push_back({sdict[prefix],i1});


            }
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
    int n ,m;//, target;
    // testcase=1 ;
    cin>>testcase;
    while (testcase--)
    {
        // cout<<endl<<checkifpallindrome("aa","c");
        // cout<<endl<<checkifpallindrome("aab","aa");
        // cout<<endl<<checkifpallindrome("aabc","cbaa");
        // cout<<endl<<checkifpallindrome("aazt","zaa");
        // cout<<endl<<checkifpallindrome("abcd","dcba");
        cin>>n ;
        vector<string> input1(n);
        for(auto &x : input1)
            cin>>x ;
        vector<vector<int>> out = palindromePairs(input1);
        cout<<endl ;
        // for(auto ind : vec)
        for (auto vec : out)
            cout<<"  "<<vec[0]<<","<<vec[1]<<"  ";
        

    }
    return 0 ;
}









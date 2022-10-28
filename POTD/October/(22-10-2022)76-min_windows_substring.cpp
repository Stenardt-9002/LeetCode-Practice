// https://leetcode.com/problems/minimum-window-substring/




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


int index(char a)
{
    if(a>='A'&&a<='Z')
        return a-'A'+26;
    return a-'a';
}

bool hash_true(vector<int> &hash_t ,vector<int> &hash_s)
{
    for (int i1 = 0; i1 < 52; i1++)
        if(hash_t[i1]>hash_s[i1])
            return false ;
    
    return true;
}

string minWindow(string s, string t) 
{
    // edge case
    // single string empty string 
    vector<int> hash_t(52,0)    ;

    for(auto x: t)
        hash_t[index(x)]++ ;

    int ans_index = 0 ,length_ans1 = INT_MAX ;
    int lengtht = t.length(),i1 =0 ;
    int lengths = s.length();
    //two pointer 
    int first_ptr = 0,second_ptr = 0 ;
    while(second_ptr<lengths) 
    {
        if(hash_t[index(s[second_ptr++])]-->0)
            lengtht--;//reducing and matching our target string 

        while (lengtht==0)
        {
            if(second_ptr-first_ptr<length_ans1)
            {
                length_ans1 = second_ptr-first_ptr ;
                ans_index = first_ptr ;
            }
            if(++hash_t[index(s[first_ptr++])]==1)//first charcter
                lengtht++ ;
        }
        
    }

    if(length_ans1==INT_MAX)
        return "";
    return s.substr(ans_index , length_ans1);


}


















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








class Solution 
{
public:


    bool pallindrome_check(string s ,int start , int end )
    {
        while(start<end)
            if(s[start++]!=s[end--])
                return false ;
        return true ;
    }



    void recusrive_func(int index,string s ,vector<string>&current ,vector<vector<string>> &ans )
    {
        if(index==s.size())
        {
            ans.push_back(current);
            return ;
        }
        for(int i = index;i<s.size();i++)
            if(pallindrome_check(s,index,i))
            {
                current.push_back(s.substr(index , i-index+1));
                recusrive_func(i+1 , s , current , ans);
                current.pop_back();
            }
        
        return ;

    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans ;
        vector<string> current ;
        recusrive_func(0,s ,current , ans );
        return ans ;
    }
};
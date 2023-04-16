
// https://leetcode.com/problems/simplify-path/




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





















class Solution {
public:
    string simplifyPath(string path) 
    {
        int i = 0 , j = 0 ;
        int n = path.length();
        stack<string> st ; 
        string temp = "";
        while(i<n)  
        {
            if(path[i]=='/')
            {
                if(temp!="")
                    st.push(temp);
                i++ ;
                while(i<n &&path[i]=='/' )
                    i++ ;    
                // cout<<i<<"get<<"<<temp<<endl;
                temp = "";
            }
            else if(path[i]=='.')
            {
                if((i+1<n&&path[i+1]=='/')||i>=n-1 )
                    i = i+2 ; 
                
                else if(i+1<n&&path[i+1]=='.' &&((i+2<n&&path[i+2]=='/' ) || i+2>=n) )
                {
                    i = i+3 ; 
                    if(st.size())
                        st.pop()          ;
                }
                else 
                {
                    temp = "";
                    while(i<n && path[i]!='/')
                        temp+=path[i++];
                }
            }
            else 
            {
                temp = "";
                while(i<n &&path[i]!='/' )
                    temp+=path[i++];
            }
            
        }  
        if(temp!="")
            st.push(temp);

        // cout<<temp ;
        // if(path[j-1]=='/')
        //     j--;
        string ans = "";
        while(st.size())
        {
            ans = "/"+st.top()+ans ; 
            st.pop();
        }
        if(ans=="")
            return "/";
        return ans ;
    }
};
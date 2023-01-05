// https://leetcode.com/problems/shortest-path-in-binary-matrix/?envType=study-plan&id=graph-i








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
    void hash_val(string temp , multiset<int>&numerator ,multiset<int>&denominator)
    {
        int n = temp.length();
        vector<int> hash(26,0);
        for(int i=0;temp[i];++i)
            hash[temp[i]-'a']++;

        numerator.insert(n);
        for(int i = 0;i<26;++i)
            if(hash[i]>1)
                denominator.insert(hash[i]);
    }
    int countAnagrams(string s) 
    {
        long long int ans = 1;
        int n = s.length();
        string temp ="";
        multiset<int> numerator ,denominator ;
        for (int i = 0; i < n; i++)
            if(s[i]==' ')
            {
                hash_val(temp , numerator , denominator);
                temp = "";
            }
            else 
                temp+=s[i];

        while (numerator.size()>0)
        {
            
        }
    
            
    }
};


int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        
    }
    

    return 0;
}







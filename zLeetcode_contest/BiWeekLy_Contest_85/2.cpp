// https://leetcode.com/contest/biweekly-contest-85/problems/time-needed-to-rearrange-a-binary-string/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





int secondsToRemoveOccurrences1(string s) 
{
    int ans1 = 0 ;
    int n = s.size(),i1=0;
    bool flag1 = true ;
    while(flag1)
    {
        set<int> indices ;
        // flag1= false ;
        i1 = 0 ;
        while(i1<n-1)
        {
            if(s[i1]=='0'&&s[i1+1]=='1')
                indices.insert(i1);
            i1++;
        }
            // {
                // s[i1] = '1';
                // s[i1+1]='0';
                // flag1 = true ;
                // i1++ ;
            // }

        if(indices.empty())
            return ans1 ; 
        // cout<<"DEUG1 ;";
        for(auto in : indices)
        {
            s[in] = '1';
            s[in+1] = '0';
            // cout<<in<<" ";
        }
        // cout<<"DEUG2 \n";
        

        ans1++ ;
    }
    return ans1-1 ;

}
int secondsToRemoveOccurrences(string s) 
{
    int ans1 = 0 ;
    int n = s.size(),i1=0;

    i1 = -1 ;
    int numofones = 0 ;
    int last_index_ofone = -1 ;
    while(++i1<n)
        if(s[i1]=='1')
        {
            numofones++;
            last_index_ofone = i1 ;
        }
    if(last_index_ofone==-1)
        return 0 ;//no ones
    if(last_index_ofone==numofones-1)
        return 0 ;
    i1 = numofones-1 ;
    // cout<<"DEUG1\n";
    // cout<<numofones<<" "<<last_index_ofone ;
    // cout<<"DEUG2\n";

    while(i1<=last_index_ofone)
    {

        if(s[i1]=='1')
            ans1++ ;
        i1++ ;
    }
    return last_index_ofone-numofones+ans1  ;
}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int  k;
    string intup ;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        // cin>>n;
        // vector<int>array_in(n,0);
        cin>>intup ;
        // cin>>k ;
        // for(int i1 = 0 ; i1<n;i1++)
        //     cin>>array_in[i1] ;
        cout<< secondsToRemoveOccurrences(intup);
        cout<<endl ;
    }
    return 0 ;
}



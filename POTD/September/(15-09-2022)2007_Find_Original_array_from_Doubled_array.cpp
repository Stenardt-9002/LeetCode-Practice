
// https://leetcode.com/problems/find-original-array-from-doubled-array/










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void DEBUG_fuc(vector<int> a , multiset<int> s1)
{
    cout<<endl ;
    cout<<"DEUG1  " ;
    for(auto x: a)
        cout<<x<<" ";
    cout<<endl ;
    cout<<"DEUG2  " ;
    for(auto x: s1)
        cout<<x<<" ";
    cout<<endl ;
}

vector<int> findOriginalArray(vector<int>& changed) 
{
    int n = changed.size();
    if(n%2==1)
        return {};
    int zerocnt = 0;
    for (int i1 = 0; i1 < n; i1++)
        if(changed[i1]==0)
            zerocnt++ ;
    
    vector<int> ans1 ;
    multiset<int> s1(changed.begin(),changed.end());    
    
    sort(changed.begin(),changed.end(),greater<int>());
    for (int i1 = n-1; i1 >=0; i1--)
        if(changed[i1]%2==0 && s1.find(changed[i1])!=s1.end() && s1.find(changed[i1]/2)!=s1.end() && s1.find(changed[i1])!=s1.find(changed[i1]/2))
            ans1.push_back(changed[i1]/2),s1.erase(s1.find(changed[i1])) ,s1.erase(s1.find(changed[i1]/2)) ;

    if(zerocnt%2)
        return {};
    for (int i1 = 0; i1 < zerocnt/2; i1++)
        ans1.push_back(0);
        
    if(ans1.size()==n/2)
    return ans1 ;

    return {};
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
        int n ;
        cin>> n ;
        vector<int> intup(n,0);
        for(auto &x:intup)
            cin>>x ;
        vector<int> out = findOriginalArray(intup);
        cout<<"DEUG3 "<<endl ;
        for(auto a : out)
            cout<<a<<" ";
        cout<<endl ;
    }
    return 0 ;
}


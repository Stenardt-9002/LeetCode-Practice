// https://leetcode.com/contest/biweekly-contest-85/problems/time-needed-to-rearrange-a-binary-string/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


string shiftingLetters(string s, vector<vector<int>>& shifts) 
{

    int n = s.size();
    vector<int> cumulative_sum(n,0);
    for(auto inpt : shifts)
    {
        if(inpt[2]==1)
        {
            cumulative_sum[inpt[0]] += 1;
            if(inpt[1]<n-1)
            cumulative_sum[inpt[1]+1] -= 1;
        }
        else if(inpt[2]==0)
        {
            cumulative_sum[inpt[0]] -= 1;
            if(inpt[1]<n-1)
            cumulative_sum[inpt[1]+1] += 1;
        }
            // cout<<"\nDEUG "<<cnter1++<<" ";
            // for(auto in : cumulative_sum)
            //     cout<<in<<" ";
            // cout<<"DEUG2 \n";
    }

    for(int i1 = 1 ; i1<n ; i1++)
        cumulative_sum[i1]+=cumulative_sum[i1-1];

        // cout<<"\n1DEBUG "<<cnter1++<<" ";
        // for(auto in : cumulative_sum)
        //     cout<<in<<" ";
        // cout<<"2DEBUG2 \n";

    int cur_char ;
    // cout<<endl ;
    for(int i1 = 0 ; i1<n ; i1++)
    {
        cur_char = s[i1]-'a';
        cur_char = (cur_char+cumulative_sum[i1])%26;
        if(cur_char<0)
            cur_char+=26 ;
        // cout<<" "<<cur_char;
        s[i1] = cur_char+'a';
    }
    // cout<<endl ;

    return s ;

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
        int n ;
        cin>>intup;
        cin>> n;
        int st , end , dir ;
        vector<vector<int>> shifts;
        for (int i1 = 0; i1 < n; i1++)
        {
            cin>>st>>end>>dir ;
            shifts.push_back({st,end,dir});
        }
        
        cout<< shiftingLetters(intup,shifts);
        cout<<endl ;
    }
    return 0 ;
}





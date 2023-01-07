// https://leetcode.com/contest/biweekly-contest-85/problems/minimum-recolors-to-get-k-consecutive-black-blocks/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int minimumRecolors(string blocks, int k) 
{
    // set<int> index_list ;
    int n = blocks.size();
    int ans1 = INT_MAX ;
    for (int start = 0; start <= n-k; start++)
    {
        int urent_op = 0 ;
        for (int cur_in = start; cur_in < start+k; cur_in++)
            if(blocks[cur_in]=='W')
                urent_op++ ;

        ans1 = min(ans1 , urent_op)        ;
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
    int  k;
    string intup ;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        // cin>>n;
        // vector<int>array_in(n,0);
        cin>>intup ;
        cin>>k ;
        // for(int i1 = 0 ; i1<n;i1++)
        //     cin>>array_in[i1] ;
        cout<< minimumRecolors(intup,k);
        cout<<endl ;
    }
    return 0 ;
}


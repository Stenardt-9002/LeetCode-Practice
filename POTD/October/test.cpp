

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




int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    vector<int> arr1 = {1,4,4,4,4,6,6,7,8,9,12,15,18} ;
    auto it = lower_bound(arr1.begin(),arr1.end(),5);
    // cout<<it-arr1.begin() ;
    auto it2 = upper_bound(arr1.begin(),arr1.end(),5);
    // cout<<endl<<it2-arr1.begin() ;
    // int testcases=1 ;
    // cin>>testcases;
    // while (testcases--)
    // {
        
    // }
    
    multiset<pair<int,int>> s1 ;
    s1.insert({10,23});
    s1.insert({14,21});
    s1.insert({6,9});
    s1.insert({5,28});

    cout<<endl<<"DEUG1 ";
    for(auto x:s1)
        cout<<x.first<<" "<<x.second<<endl ;

    return 0;
}


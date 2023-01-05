







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
struct new_data 
{
    int plantseed ,growtime ;
};

bool compare(struct new_data a1 , struct new_data b1)
{
    return (a1.growtime>b1.growtime);

    // if(a1.growtime>b1.growtime)
    //     return true ;
    // return a1.plantseed>b1.plantseed;
}
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
{
    int n = plantTime.size();
    vector<new_data> array1;
    for (int i1 = 0; i1 < n; i1++)
        array1.push_back({plantTime[i1] , growTime[i1]});


    sort(array1.begin() , array1.end() , compare);
    ll ans1 = array1[0].growtime+array1[0].plantseed;
    ll cur_sum = array1[0].plantseed ;
    for (int i1 = 1; i1 < n; i1++)
    {
        cur_sum += array1[i1].plantseed ;
        ans1 = max(ans1 , cur_sum+array1[i1].growtime);
    }

    // for (int i1 = 0; i1 < n; i1++)
    //     cout<<" "<<array1[i1].plantseed<<" "<<array1[i1].growtime<<endl;
    

    return ans1 ;

}




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
        int n ;
        cin>>n;
        vector<int> a1(n) ,b1(n);
        for(auto &x:a1)
            cin>>x ;
        for(auto &x:b1)
            cin>>x ;        
        cout<<earliestFullBloom(a1,b1);
        cout<<endl;
    }
    

    return 0;
}









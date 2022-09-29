

// https://leetcode.com/problems/my-calendar-i/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



class MyCalendar {
public:
    set<pair<int,int>> input1_vector ;
    MyCalendar() 
    {

    }
    
    bool book(int start, int end) 
    {
        auto position1 = input1_vector.lower_bound({start,end});
        if(position1!=input1_vector.end() && position1->first<end)
            return false ;
        if(position1!=input1_vector.begin() && start<(--position1)->second )
            return false ;

        input1_vector.insert({start,end});
        return true ;
    }



};




int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n,a,b;
    testcase=1 ;
    while (testcase--)
    {
        cin>>n>>a>>b ;
        vector<long long int>arr1(n,0);
        for (long long int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1];

        //all subsets  
        long long int subset_count = 1 ;
        for (long long int i1 = 0; i1 < n; i1++)
        {
            long long int sum12  = 0;
            for (long long int j1 = i1; j1 < n; j1++)
            {
                sum12+=arr1[j1];
                if(sum12>=min(a,b) &&sum12<=max(a,b))
                    subset_count++ ;
            }
        }   
        cout<<subset_count<<endl ;


    }
    return 0 ;
}



// https://leetcode.com/problems/single-threaded-cpu/















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











bool comparator(vector<int> a , vector<int> b)
{
    if(a[0]<b[0])
        return true ;
    if(a[0]==b[0])
        return a[1]<b[1];
    return false ;
}




class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        long long int n = tasks.size()  ,i=0,time_c=0  ;
        vector<int> ans1 ;
        multiset<vector<int>>s1 ;
        for (i = 0; i < n; i++)
            tasks[i].push_back(i);

        // sort(tasks.begin() , tasks.end() , comparator);
        sort(tasks.begin() , tasks.end() );
        i = 0 ;
        while(i<n || s1.size())
        {
            if(s1.empty())
                time_c = max(time_c ,(ll)(tasks[i][0]));
            while(i<n && time_c>=tasks[i][0])
            {
                s1.insert({tasks[i][1] , tasks[i][2]});
                ++i ;
            }
            vector<int> temp = *(s1.begin());
            s1.erase(s1.begin());
            int cur_i = temp[1] ; 
            time_c += temp[0];

            ans1.push_back(cur_i);
        }
        return ans1 ;
    }
};



int main()
{
    set<vector<int>> s1;
    s1.insert({1,2});
    s1.insert({2,4});
    s1.insert({9,11});
    s1.insert({5,6});
    for(auto v : s1)
    {
        cout<<v[0]<<" "<<v[1]<<endl ;
    }
}
// https://leetcode.com/problems/ipo/
















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

















class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        
        int i, n = profits.size();
        vector<pair<int,int>> newarray;
        priority_queue<int> s1 ;

        for (i = 0; i < n; i++)
            newarray.push_back({ capital[i], profits[i]});
        sort(newarray.begin() , newarray.end());
        i = 0 ;

        while (k--)
        {

            while(i<n && w>=newarray[i].first)
                s1.push(newarray[i++].second);
            if(s1.size()==0)
                break ;
            w+= (s1.top());
            s1.pop();

        }
        return w ;
    }
};









// int main()
// {
//     multiset<vector<int>> s1 ;
//     s1.insert({2,4});
//     s1.insert({2,1});
//     s1.insert({5,8});
//     s1.insert({3,9});

//     for (auto itr = s1.begin(); itr !=s1.end(); itr++)
//         cout<<(*itr)[0]<<" "<<(*itr)[1]<<endl ;

//         // cout<<itr->first<<" "<<itr->second <<endl ;
    
//     return 0 ;
// }


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
        int k , w ,n;
        cin>>k>>w>>n ;
        vector<int> profits(n) ,capital(n) ;
        for (int i = 0; i < n; i++)
            cin>>profits[i];
        
        for (int i = 0; i < n; i++)
            cin>>capital[i];
        
        Solution obj1 ;
        cout<<obj1.findMaximizedCapital(k , w, profits,capital)<<endl;
    }
    

    return 0;
}













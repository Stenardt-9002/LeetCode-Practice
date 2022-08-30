// https://leetcode.com/problems/minimum-number-of-refueling-stops/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






vector<int> movesToStamp(string stamp, string target) 
{
  int total_time = 0, turns_count = -1;
  vector<int> ans1 ;
  while (turns_count) 
  {
      turns_count = 0;
      for (int sz = stamp.size(); sz > 0; --sz) 
          for (int i = 0; i <= stamp.size() - sz; ++i) 
          {
              string stamp1 = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
              auto pos = target.find(stamp1);
              while (pos != string::npos) 
              {
                  ans1.push_back(pos);
                  turns_count += sz;
                  fill(begin(target) + pos, begin(target) + pos + stamp.size(), '*');
                  pos = target.find(stamp1);
              }
          }
      total_time += turns_count;
  }

  reverse(begin(ans1), end(ans1));
  return total_time == target.size() ? ans1 : vector<int>();
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    string s,t ;
    while (testcase--)
    {
        cin>>s>>t;
        vector<int> out = movesToStamp(s,t);
        for(auto x : out)
            cout<<x<<" ";
        cout<<endl ;
    }
    return 0 ;
}




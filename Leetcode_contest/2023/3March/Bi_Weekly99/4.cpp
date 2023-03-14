
















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







class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) 
    {
        int n = edges.size();
        ++n ;
        set<int> possible_parents ;
        vector<int> parent(n , -1);
        vector<int> maximum_guess(n,0);
        vector<set<int>> graph(n);
        for(auto ed: edges)
        {
            graph[ed[0]].insert(ed[1]);
            graph[ed[1]].insert(ed[0]);
        }
        for(auto possible_edges : guesses)
        {
            int paren_t1 = possible_edges[0];
            int child_1 = possible_edges[1];
            auto pos = find(graph[paren_t1].begin(),graph[paren_t1].end() , child_1 );
            if(pos!=graph[paren_t1].end())
            {
                parent[paren_t1] = child_1 ;
                possible_parents.erase(child_1);
                graph[paren_t1].erase(pos);
            }
        }

        for(auto parent_c:possible_parents)
        {
            stack<int> s1 ;
            s1.push(parent_c);
            while (!s1.empty())
            {
                int child = s1.top()               ;
                s1.pop();
                ++maximum_guess[child];
                for(auto further: graph[child])
                    if(further!=parent[child])
                        s1.push(further);
            }
        }
        int final_ans = 0 ;
        for(auto c : maximum_guess)
            if(c>=k)
                final_ans++ ;

        return final_ans;

    }
};
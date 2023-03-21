











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

















struct ListNode 
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// inline bool operator<(const ListNode* &lhs, const ListNode* &rhs)
// {
//   return lhs->val<rhs->val;   
// }
 
 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        multiset<pair<int,ListNode*>> s1 ;
        for(auto nodes:lists)
            if(nodes)
                s1.insert({nodes->val , nodes});

        ListNode *ans = new ListNode(-1);
        ListNode* itr = ans ;
        while (s1.size())
        {
            ListNode* tp = s1.begin()->second;
            s1.erase(s1.begin());
            itr->next = tp ;
            itr = itr->next ;
            tp = tp->next ;
            if(tp!=NULL)
                s1.insert({tp->val, tp});
        }
        return ans->next ;

    }
};
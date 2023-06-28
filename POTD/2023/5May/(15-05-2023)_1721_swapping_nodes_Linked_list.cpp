// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/











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





  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };










class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *first = head,*second = head ,*temp = NULL ;
        int i = 0 ;
        while(i++<k-1)
            first = first->next ;
        
        temp = first ; 
        first = first->next ;
        
        while(first!=NULL)
        {
            first = first->next ; 
            second = second->next ;
        }
        swap(second->val , temp->val );
        return head ;

    }
};








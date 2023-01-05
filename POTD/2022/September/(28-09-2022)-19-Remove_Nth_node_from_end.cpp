// https://leetcode.com/problems/remove-nth-node-from-end-of-list/



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



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head->next==NULL && n==1)
            return NULL ;
        
        ListNode *traverse = new ListNode();
        traverse->next = head ;
        
        ListNode *first = traverse , *second = traverse ;
        
        int i1 = 0 ;
        
        while(second->next!=NULL)
        {
            if(++i1>n)
                first = first->next ;
            second = second->next ;
                
        }
        
        if(first->next !=NULL)
            first->next = first->next->next ;
        
        return traverse->next ;
    }






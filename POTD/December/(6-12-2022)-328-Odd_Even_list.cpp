// https://leetcode.com/problems/odd-even-linked-list/





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




ListNode* oddEvenList(ListNode* head) 
{
    if (head==NULL || head->next==NULL || head->next->next==NULL)
        return head ;
    ListNode *first = head , *second = head->next ,*second_head = head->next;
    while (1)
    {
        
        first->next = second->next ;
        first = first->next ;
        if(first!=NULL)
            second->next = first->next ;
        second = second->next ;
        if(second==NULL)
            break;
        
    }
    first = head ;
    while(first->next!=NULL)
        first = first->next ;

    first->next = second_head ;
    
    return head ;
}





















// https://leetcode.com/problems/linked-list-cycle-ii/description/













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
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL|| head->next==NULL)
            return NULL ;


        ListNode* first = head , *second = head ;
        ListNode* temp = head ;
        while(second->next!=NULL && second->next->next!=NULL)    
        {
            first = first->next;
            second = second->next->next ;
            if(first==second)
            {
                while(temp!=first)
                {
                    temp = temp->next ;
                    first = first->next ;
                }
                return temp ;
            }
        }
        return NULL ;
    }
};
// https://leetcode.com/problems/middle-of-the-linked-list/description/



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
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head ;
        ListNode *slow = head ;ListNode *fast = head ;
        while(slow->next!=NULL&&fast->next!=NULL)
        {
            slow = slow->next ;
            fast = fast->next ;
            if(fast->next!=NULL)
                fast = fast->next ;
        }
        return slow ;
    }
};
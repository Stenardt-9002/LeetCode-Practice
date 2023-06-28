// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
 







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
    int pairSum(ListNode* head) {
        int ans = 0 ;
        ListNode* slow = head , *fast = head ;
        while(fast && fast->next)
        {
            fast = fast->next->next ;
            slow = slow->next;
        }
        ListNode* nextNode , *prev = NULL ;
        //reverse from middle
        while(slow)
        {
            nextNode = slow->next ;
            slow->next = prev ;
            prev = slow ;
            slow = nextNode;
        }
        while(prev!=NULL&& head!=NULL)
        {
            ans = max(ans , prev->val+head->val);
            prev = prev->next ;
            head = head->next;
        }


        return ans ;
    }
};
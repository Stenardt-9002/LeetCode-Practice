// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/





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




ListNode* deleteMiddle(ListNode* head) 
{
    if(head->next==NULL)
        return NULL ;

    ListNode *slowtra = head ;
    ListNode *fasttra = head ;
    ListNode *prev = head ;
    while (fasttra->next!=NULL )
    {   
        prev = slowtra ;
        slowtra = slowtra->next;
        fasttra = fasttra->next;
        if(fasttra->next!=NULL)
            fasttra = fasttra->next;

    }
    prev->next = prev->next->next;
    return head ;
}







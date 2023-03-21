// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/














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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };







TreeNode* util_recursive(ListNode *start , ListNode* end)
{
    if(start==end)
        return NULL ;
    ListNode* slow = start ;ListNode* fast = start ;
    // two ptr 
    while(fast!=end && fast->next!=end)
    {
        slow = slow->next ;
        fast = fast->next->next ;
    }
    TreeNode* mainNode = new TreeNode(slow->val);
    mainNode->left = util_recursive(start , slow);
    mainNode->right = util_recursive(slow->next , end);
    return mainNode ;
}


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return util_recursive(head , NULL);
    }
};
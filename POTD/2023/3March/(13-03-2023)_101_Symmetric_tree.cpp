// https://leetcode.com/problems/symmetric-tree/












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




  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


bool inorder_tree(TreeNode* root , TreeNode* reverseroot)
{
    if(root==NULL && reverseroot==NULL)
        return true ;
    else if(root==NULL || reverseroot==NULL)
        return false ;

    return (root->val==reverseroot->val)&&inorder_tree(root->left, reverseroot->right)&&inorder_tree(root->right, reverseroot->left);


}



class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        return inorder_tree(root , root);
    }
};










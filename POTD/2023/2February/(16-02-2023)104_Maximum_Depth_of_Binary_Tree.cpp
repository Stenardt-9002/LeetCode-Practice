// https://leetcode.com/problems/maximum-depth-of-binary-tree/










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


//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

int get_recursive(TreeNode * node1)
{
    if(node1==NULL)
        return 0 ;
    return 1 + max(get_recursive(node1->left) , get_recursive(node1->right));
}


class Solution {
public:
    int maxDepth(TreeNode* root) {
        return get_recursive(root);
    }
};








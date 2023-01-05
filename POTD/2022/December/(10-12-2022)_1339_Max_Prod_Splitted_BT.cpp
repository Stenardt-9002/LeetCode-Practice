
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/










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




class Solution {
public:
    static ll get_sum_tree(TreeNode* root) 
    {
        if(root==NULL)
            return 0 ;
        return (root->val+get_sum_tree(root->left)+get_sum_tree(root->right))%mod1 ;
    }

    static ll ge_dfs(TreeNode *root , ll total_sum , ll &ans)
    {
        if(root==NULL)
            return 0 ;
        
        ll diff = ge_dfs(root->left , total_sum , ans)+ge_dfs(root->right , total_sum , ans)+root->val;
        ans = max({ans , diff*(total_sum-diff)});
        ans;
        return diff;
    }

    int maxProduct(TreeNode* root) 
    {
        int totalsum1 = get_sum_tree(root)    ;
        ll ans1 = 0 ;
        ge_dfs(root , totalsum1 , ans1);
        return ans1%mod1 ;    
    }
};





































// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/









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


struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int dfs_util_mmin_max(TreeNode *root , int min_val , int max_val)
{
    if(root==NULL)
        return max_val-min_val ;

    max_val = max(max_val , root->val);
    min_val = min(min_val , root->val);
    return max(dfs_util_mmin_max(root->left , min_val , max_val) ,dfs_util_mmin_max(root->right , min_val , max_val) );

    
}



int maxAncestorDiff(TreeNode* root) 
{
    return dfs_util_mmin_max(root , root->val , root->val);
}















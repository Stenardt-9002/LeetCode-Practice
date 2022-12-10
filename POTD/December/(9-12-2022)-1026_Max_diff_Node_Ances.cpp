// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/



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















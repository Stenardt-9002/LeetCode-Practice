    
struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void inorder_Traversal(TreeNode *curr , int low , int high , int &ans1 )
{
    if(curr==nullptr)
        return ;

    inorder_Traversal(curr->left , low , high , ans1);
    if(curr->val>=low && curr->val <=high)
        ans1+=curr->val;
    inorder_Traversal(curr->right , low , high , ans1);
    
}


    
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int ans1 = 0 ;
        inorder_Traversal(root , low , high , ans1) ; 
        return ans1 ;
    }
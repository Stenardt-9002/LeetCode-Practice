// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder_traveral(TreeNode* root , TreeNode* &ans1)
{
    if(root==NULL)
        return ;
    ans1->right = new TreeNode(root->val);
    ans1 = ans1->right;
    preorder_traveral(root->left , ans1);
    preorder_traveral(root->right , ans1);

}


void flatten(TreeNode* root) 
{
    if(root==NULL)
        return ;

    TreeNode *ans1 = new TreeNode(-1);
    TreeNode *orig = ans1 ;
    preorder_traveral(root,ans1);
    root->right = orig ;

    root->left = NULL ;

    root->val = orig->right->val ;
    root->right = orig->right->right ;
    // root = root->right ;
    // root = root->right ;

        // while (root!=NULL)
        // {
        //     cout<<" "<<root->val ;
        //     root = root->right ;
        // }
}

void flatten(TreeNode* root) 
{
    if(root==NULL)
        return ;

    TreeNode *cur = root;
    TreeNode *prev = NULL  ;
    
    while(cur!=NULL)
    {
        if(cur->left!=NULL)
        {
            prev = cur->right ;
            while (prev->right!=NULL)
                prev = prev->right ;

            prev->right = cur->right ;
            cur->right = cur->left ;
            cur->left = NULL ;
        }
        cur = cur->right ;
    }

}





int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    flatten(root);  
    while (root!=NULL)
        {
            cout<<" "<<root->val ;
            root = root->right ;
        }
    
            
    return 0 ;
}




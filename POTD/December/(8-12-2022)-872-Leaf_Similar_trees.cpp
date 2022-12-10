// https://leetcode.com/problems/leaf-similar-trees/







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


void inorder_traversal(TreeNode *root , vector<int>&ans1)
{
    if(root->left==NULL && root->right==NULL)
        ans1.push_back(root->val);

    if(root->left!=NULL)
        inorder_traversal(root->left , ans1);
    
    if(root->right!=NULL)
        inorder_traversal(root->right , ans1);
    
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
    vector<int> ans1 ,ans2;    
    inorder_traversal(root1 , ans1);
    inorder_traversal(root2 , ans2);


    if(ans1.size()!=ans2.size())
        return false ;
    
    int n = ans1.size();
    for (int i = 0; i < n; i++)
        if(ans1[i]!=ans2[i])
            return false ;
    

    return true ;
}







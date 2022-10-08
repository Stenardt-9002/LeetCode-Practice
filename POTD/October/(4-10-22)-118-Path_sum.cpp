
// https://leetcode.com/problems/path-sum/

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

const long long int mod2 =  1e18 ;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
            return false ;
        // if(targetSum<root->val)
        //         return false ;
        bool ans1 = false ;
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==root->val)
                return true ;
            return false ;
        }
        if(root->left!=NULL)
        ans1 = ans1||hasPathSum(root->left,targetSum-root->val);
        if(root->right!=NULL)
        ans1 = ans1||hasPathSum(root->right,targetSum-root->val);
        
        return ans1 ;
    }

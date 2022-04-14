// https://leetcode.com/problems/binary-tree-maximum-path-sum/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



int maxSum_util(TreeNode* root,int &maxi) 
{
    if(root==NULL)
        return 0;
    int left_sum = maxSum_util(root->left , maxi);
    int right_sum = maxSum_util(root->right , maxi);

    maxi = std::max(maxi,root->val+left_sum+right_sum);
    return root->val+std::max(left_sum,right_sum);
}


    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int ans1 ;
        return maxSum_util(root, ans1);
    }




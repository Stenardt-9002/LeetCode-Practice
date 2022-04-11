// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/




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

  class SpecialData 
  {
      public:
      int sum1 ,max1,min1;
      bool isbST ;
      SpecialData()
      {
          sum1=0;max1=INT_MIN ;min1=INT_MAX ; 
          isbST=true;
      }
  };

//sum,BST,max left,min right
SpecialData check_if_BStree(TreeNode* root,int &sum_val )
{
    if(root==NULL)
    {
        SpecialData ans1 ;
        return ans1;
    }



    SpecialData left_side = check_if_BStree(root->left,sum_val);
    SpecialData right_side = check_if_BStree(root->right,sum_val);
    SpecialData ans1 ;
    if(left_side.isbST && right_side.isbST && root->val>left_side.max1 && root->val<right_side.min1)
    {
        ans1.sum1 = left_side.sum1+root->val+right_side.sum1;
        // std::cout<<"\nOne "<<ans1.first<<" "<<root->val<<endl;
        // std::cout<<"\nOne "<<" "<<root->val<<" "<<left_side.first<<" "<<right_side.first<<" "<<max<<" "<<min<<endl;
        ans1.max1 = std::max({root->val,left_side.max1,right_side.max1});
        ans1.min1 = std::min({root->val,left_side.min1,right_side.min1});
        ans1.isbST = true ;
        // return ans1 ;
    }
    else 
    {
        ans1.sum1 = std::max(left_side.sum1,right_side.sum1);
        // std::cout<<"\nTwo "<<" "<<root->val<<" "<<left_side.first<<" "<<right_side.first<<" "<<max<<" "<<min<<endl;
        ans1.isbST = false ;
        // return ans1 ;
    }
    sum_val = max(sum_val, ans1.sum1);
    return ans1 ;
}



int maxSumBST(TreeNode* root) 
{
    if(root==NULL)
        return 0;

    int ans1 = INT_MIN ;
    SpecialData p1 = check_if_BStree(root,ans1) ;
    // sum , BST, max,min 

    // return p1.sum1 ;
    return ans1>0?ans1:0;
}



int main(int argc, char const *argv[])
{
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(-6);
    // root->right->right = new TreeNode(2);
    // cout<<findLagestSubtree(root)<<endl;;


    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode(5);
    // root->right->right->left = new TreeNode(4);
    // root->right->right->right = new TreeNode(6);


    // TreeNode* root = new TreeNode(-4);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(-5);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode(5);
    // root->right->right->left = new TreeNode(4);
    // root->right->right->right = new TreeNode(6);


    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    // root->right = new TreeNode(-5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(1);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(-5);
    root->left->right->right = new TreeNode(4);
    root->left->right->left->right = new TreeNode(-3);
    root->left->right->right->right = new TreeNode(10);



    std::cout<<" "<<maxSumBST(root)<<endl;



    return 0;
}





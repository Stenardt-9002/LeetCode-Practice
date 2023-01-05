// https://leetcode.com/problems/count-good-nodes-in-binary-tree/










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };




void dfs_util(TreeNode* node1 , int maxvalue_allowed , int &ans1)
{
    if(node1==NULL)
        return  ;
    if(node1->val>=maxvalue_allowed)
        ans1++ ;
    maxvalue_allowed = max(maxvalue_allowed , node1->val);
    dfs_util(node1->left , maxvalue_allowed , ans1);
    dfs_util(node1->right , maxvalue_allowed , ans1);


}



int goodNodes(TreeNode* root) 
{
    int ans1 = 0 ;
    dfs_util(root , INT_MIN ,ans1);
    return ans1 ;

}





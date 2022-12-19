// https://leetcode.com/problems/binary-tree-maximum-path-sum/











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


    static int dfs_util(TreeNode* root , int &max_ans)
    {
        if(root==NULL)
            return 0 ;

        
        int left_sum = max(0,dfs_util(root->left , max_ans));
        int right_sum = max(0,dfs_util(root->right , max_ans));

        max_ans = max(max_ans , root->val+left_sum+right_sum);
        return root->val+max(left_sum , right_sum);
    }

    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL)
            return 0 ;
        int ans1 = INT_MIN ;
        int current_path = dfs_util(root , ans1);
        ans1 = max(ans1 , current_path);
        return ans1 ;

    }
};







// https://leetcode.com/problems/path-sum-ii/



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


void dfs_util(TreeNode* cur_node , vector<vector<int>>&ans1 , vector<int> current_in ,int dum1 , int target_sum )
{
    current_in.push_back(cur_node->val);
    dum1+=cur_node->val ;
    if( cur_node->left==NULL&&cur_node->right==NULL)
    {
        if(target_sum==dum1)
            ans1.push_back(current_in);
        return ;
    }
    if(cur_node->left!=NULL)
        dfs_util(cur_node->left , ans1 , current_in ,dum1 , target_sum);
    if(cur_node->right!=NULL)
        dfs_util(cur_node->right , ans1 , current_in ,dum1 , target_sum);
    
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    vector<vector<int>> ans1 ;
    int sum1 = 0 ;
    vector<int>temp1 ;
    if(root!=NULL)
    dfs_util(root , ans1,temp1 ,sum1 , targetSum );
    return ans1;
}



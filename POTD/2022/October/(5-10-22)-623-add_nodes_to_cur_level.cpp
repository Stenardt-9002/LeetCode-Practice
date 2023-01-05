// https://leetcode.com/problems/add-one-row-to-tree/





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

TreeNode* addOneRow(TreeNode* root, int val, int depth) 
{
    if(depth==1)
    {
        TreeNode* new_ndoe = new TreeNode(val);
        new_ndoe->left = root ;
        return new_ndoe ;
    }

    queue<TreeNode*> q1 ;
    int depth_count = 1 ;
    q1.push(root);
    while (!q1.empty())
    {
        int n = q1.size();
        if(++depth_count==depth)
        {        
            for (int i1 = 0; i1 < n; i1++)
            {
                TreeNode *temp = q1.front();
                q1.pop();
                TreeNode *temp_left = temp->left ;
                TreeNode *temp_right = temp->right ;
                temp->left = new TreeNode(val);
                temp->left->left = temp_left ;
                temp->right = new TreeNode(val);
                temp->right->right = temp_right ;
                
            }
            return root ;
        }
        for (int i1 = 0; i1 < n; i1++)
        {
            TreeNode *temp = q1.front();
            q1.pop();
            if(temp->left!=NULL)
                q1.push(temp->left);
            if(temp->right!=NULL)
                q1.push(temp->right);
        }

    }
    return root ;



}




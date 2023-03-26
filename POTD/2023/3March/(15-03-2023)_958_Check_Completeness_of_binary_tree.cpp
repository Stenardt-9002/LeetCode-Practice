// https://leetcode.com/problems/check-completeness-of-a-binary-tree/






























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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*>q1;
        bool break_loop = true ;
        q1.push(root);
        while(q1.size()&& break_loop)    
        {
            int n = q1.size();
            while(n-- && break_loop)
            {
                TreeNode* front = q1.front();
                q1.pop();
                if(front==NULL)
                {
                    break_loop = false ;
                    break ;
                }
                q1.push(front->left);q1.push(front->right);
            }
        }
        while(q1.size())
        {
            TreeNode* front = q1.front();
            q1.pop();
            if(front!=NULL)
                return false ;
        }
        return true ;
    }
};
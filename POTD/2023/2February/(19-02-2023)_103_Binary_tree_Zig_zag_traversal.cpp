
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/  

















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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        vector<vector<int>> ans ;
        queue<TreeNode*> q1 ;
        q1.push(root);
        bool flag = false ;
        while(!q1.empty())
        {
            int n = q1.size();
            vector<int> temp ;
            for(int i = 0;i<n;i++)
            {
                TreeNode* noed = q1.front();
                q1.pop();
                temp.push_back(noed->val);
                if(noed->left!=NULL)
                    q1.push(noed->left);

                if(noed->right!=NULL)
                    q1.push(noed->right);
            }
            if(flag)
                reverse(temp.begin(),temp.end());
            flag = !flag;
            ans.push_back(temp);
        }
        return ans ;
    }
};
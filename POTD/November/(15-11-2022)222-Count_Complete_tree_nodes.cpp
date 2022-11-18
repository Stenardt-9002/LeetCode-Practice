// https://leetcode.com/problems/count-complete-tree-nodes/








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

    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        vector<TreeNode*>arr1;
        arr1.push_back(root);
        int current_ptr =0;
        while(1)
        {
            if(arr1[current_ptr]->left!=NULL)
                arr1.push_back(arr1[current_ptr]->left);
            else break;

            if(arr1[current_ptr]->right!=NULL)
                arr1.push_back(arr1[current_ptr]->right);
            else break;
            current_ptr++;
        }

        return arr1.size();
    }







// https://leetcode.com/problems/find-duplicate-subtrees/description/


















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









string save_string(TreeNode* node ,unordered_map<string , vector<TreeNode*>>&hash_node)
{
    if(node==NULL)
        return "";
    string te = "("+save_string(node->left , hash_node)+to_string(node->val)+save_string(node->right , hash_node)+")";
    hash_node[te].push_back(node);
    return te; 
}


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string , vector<TreeNode*>>hash_node ;
        vector<TreeNode*> ans ; 
        save_string(root , hash_node);
        for(auto child:hash_node)
            if(child.second.size()>1)
                ans.push_back(child.second.back());

        return ans ; 
    }
};


















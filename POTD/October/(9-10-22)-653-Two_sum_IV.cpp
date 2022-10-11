// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/


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




struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool dfs_util(TreeNode* root, int k , unordered_set<int> &s1) 
{
    if(root==NULL)
        return false ;
    if(s1.find(k-root->val)!=s1.end())
        return true ;
    s1.insert(root->val);
    return dfs_util(root->left , k , s1)||dfs_util(root->right , k , s1);
}

bool findTarget(TreeNode* root, int k) 
{
    if(root==NULL)
        return false ;
    unordered_set<int> s1;
    return dfs_util(root , k , s1);

}


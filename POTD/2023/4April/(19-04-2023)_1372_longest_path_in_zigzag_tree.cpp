// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/







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
    vector<int> recursive_func(TreeNode* root) 
    {
        if(root==NULL)
            return {-1,-1,-1};
        vector<int> leftfirst = recursive_func(root->left) ;
        vector<int> rightfirst = recursive_func(root->right) ;
        int ans = max({leftfirst[1]+1,rightfirst[0]+1 , leftfirst[2] ,rightfirst[2]});
        return {leftfirst[1]+1 , rightfirst[0]+1 , ans};
        
    }
    int longestZigZag(TreeNode* root) 
    {
        if (root==NULL)
            return 0 ;
        
        return recursive_func(root)[2];
    }
};





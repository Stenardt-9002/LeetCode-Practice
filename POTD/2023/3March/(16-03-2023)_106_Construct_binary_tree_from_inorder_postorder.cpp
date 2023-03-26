// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/













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
TreeNode* util_create_tree(vector<int>inorder , vector<int>postorder ,int start , int end , int &cureentindex , unordered_map<int,int>&hash)    
{
    if(start>end)
        return NULL ;

    TreeNode* node = new TreeNode(postorder[cureentindex]);
    cureentindex-- ;
    if(start==end)
        return node ;
    
    int position = hash[postorder[cureentindex+1]];

    node->right = util_create_tree(inorder , postorder ,position+1 , end , cureentindex , hash);
    node->left = util_create_tree(inorder , postorder ,start, position-1 , cureentindex , hash);

    return node ;    
    
}


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
        unordered_map<int,int> hash ;
        for (int i = 0; i < n; i++)
            hash[inorder[i]] = i ;

        int cure_index = n-1 ;
        return util_create_tree(inorder , postorder ,0, n-1 , cure_index , hash)    ;
    }
};











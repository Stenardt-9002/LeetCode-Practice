// https://leetcode.com/problems/find-duplicate-subtrees/



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;




  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



string ionrderUtil(TreeNode *root , unordered_map<string,int> &hash_map,vector<TreeNode *> &ans1)
{
    if(root==NULL)
        return "";

    string str1 = "(";
    str1+=ionrderUtil(root->left,hash_map,ans1);
    str1+=to_string(root->val);
    str1+=ionrderUtil(root->right,hash_map,ans1);
    str1+=")";
    if(hash_map.find(str1)==hash_map.end())//not found
        hash_map[str1]=1 ;
    else
    {
        hash_map[str1]+=1 ;
        if(hash_map[str1]==2 )
            ans1.push_back(root);
    }
    return str1 ;
}


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
            unordered_map<string,int> hash_map ;
            vector<TreeNode *> ans1 ; 
            ionrderUtil(root, hash_map ,ans1);
            return ans1 ;    
    }


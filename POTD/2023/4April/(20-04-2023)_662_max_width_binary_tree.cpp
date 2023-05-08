// https://leetcode.com/problems/maximum-width-of-binary-tree/




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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0 ;
        int ans = 1 ;
        queue<pair<TreeNode*,long long int>> q1 ;
        q1.push({root,0});//node and index
        while(q1.size())
        {  
            int size = q1.size();
            int firstfront = q1.front().second , secondfront=q1.back().second;
            ans = max(ans,secondfront-firstfront+1);
            for(int i=0;i<size ; i++)
            {
                pair<TreeNode* , int> p = q1.front();
                q1.pop();
                int temp = p.second-firstfront;
                if(p.first->left!=NULL)
                    q1.push({p.first->left ,(long long)temp*2+1});
                if(p.first->right!=NULL)
                    q1.push({p.first->right ,(long long)temp*2+2});
            }     
        }
        return ans ; 
    }
};
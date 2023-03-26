// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/










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





















void util(TreeNode* root , int cur, int &nas)
{
    if(root->left==NULL&& root->right==NULL)
    {
        nas+=(10*cur+root->val) ;
        return ;
    }
    if(root->left)
    util(root->left, cur*10+root->val , nas);
    if(root->right)
    util(root->right, cur*10+root->val , nas);
}



class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        int ans = 0 ;
        util(root , 0 , ans)    ;
        return ans ;
    }
};
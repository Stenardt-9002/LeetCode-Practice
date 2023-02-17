






// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/











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











    int minDiffInBST(TreeNode* root) 
    {
        TreeNode *cur, *pre ;
        

        if(root==NULL)
            return 0 ;
        int ans = INT_MAX ; 
        int previous = -1 , current =-1 ;
        cur = root ;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                previous = current ;
                current = cur->val ;
                cur = cur->right ;
                if(previous!=-1 && current!=-1)
                    ans = min(ans , current-previous);
                
            }
            else 
            {
                pre = cur->left ;
                while(pre->right!=NULL && pre->right!=cur)
                    pre = pre->right ;
                
                if(pre->right==NULL)
                {
                    pre->right = cur ;
                    cur = cur->left ;
                }
                else 
                {
                    pre->right = NULL ;
                    previous = current ;
                    current = cur->val ;
                    cur = cur->right ;
                    if(previous!=-1 && current!=-1)
                    ans = min(ans , current-previous);
                }
            }
        }
        return ans ; 

    }
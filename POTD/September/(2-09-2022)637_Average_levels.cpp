

// https://leetcode.com/problems/average-of-levels-in-binary-tree/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q1 ;
        vector<double> ans1 ;
        q1.push(root);
        while(!q1.empty())
        {
            int size1 = q1.size();
            double sum1 = 0 ;
            for(int i1 = 0 ; i1<size1 ; i1++)
            {
                sum1+=q1.front()->val;
                TreeNode* temp = q1.front() ;
                if(temp->left!=NULL)
                    q1.push(temp->left);
                if(temp->right!=NULL)
                    q1.push(temp->right);
                
                q1.pop();
                
            }
            ans1.push_back(sum1/size1);
        }
        
        return ans1 ;
    }
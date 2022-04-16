



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



void print_path_ytil(TreeNode* root,ll1d cur1 , ll1d targetSum ,ll1d &total1 ,unordered_map<ll1d,ll1d>&has_ma )
{
  if(root==NULL)
    return ;

    cur1+=root->val;
    if(has_ma.find(cur1-targetSum)!=has_ma.end())
      total1+=has_ma[cur1-targetSum];
    
    has_ma[cur1]++;

    print_path_ytil(root->left,cur1,targetSum,total1,has_ma);
    print_path_ytil(root->right,cur1,targetSum,total1,has_ma);
    has_ma[cur1]--;
}


int pathSum(TreeNode* root, int targetSum) 
{
    vector<ll1d> current_path;
    unordered_map<ll1d,ll1d> has_ma ;
    has_ma[0]=1 ;
    ll1d toal1 = 0;
    ll1d cur1 = 0;
    print_path_ytil(root , cur1 ,targetSum,toal1, has_ma);
    return toal1;
}




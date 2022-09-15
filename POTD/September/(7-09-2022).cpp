    

    



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    
string tree2str(TreeNode* root) 
{
        if (root == NULL) return "";
        string s = to_string(root->val);

        if (root->left) 
            s += '(' + tree2str(root->left) + ')';
        else if (root->right) 
            s += "()";

        if (root->right) 
            s += '(' + tree2str(root->right) + ')';
        return s;
}
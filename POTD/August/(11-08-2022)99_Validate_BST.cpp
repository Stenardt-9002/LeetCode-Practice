
// https://leetcode.com/problems/validate-binary-search-tree/





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

// bool checkutil(TreeNode* root , long long min1 , long long max1)
// {
//     if (root==NULL)
//         return true ;
    
//     if(root->val<min1||root->val>max1)
//         return false ;

//     return (checkutil(root->left , min1 , root->val-1) && checkutil(root->right ,  root->val+1 , max1));

// }



bool isValidBST(TreeNode* root) 
{
    // return checkutil(root,INT_MIN , INT_MAX );
    if(root==NULL)  
    return true ;
    stack<TreeNode*>s1 ;

    TreeNode *prev= NULL ;
    while (root!=NULL || !s1.empty())
    {
        while(root!=NULL)
        {
            s1.push(root) ;
            root = root->left ;
        }
        root = s1.top();
        s1.pop();
        if(prev!=NULL && root->val<=prev->val)
            return false ;
        prev = root ; 
        root = root->right ;
    }
    return true ;
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n,a,b;
    testcase=1 ;
    while (testcase--)
    {
        cin>>n>>a>>b ;

    }
    return 0 ;
}



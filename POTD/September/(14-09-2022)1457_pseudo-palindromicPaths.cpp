// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/








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


void DEBUG1(vector<int> array)
{
    cout<<endl ;
    for(int i1 = 1 ; i1<10 ; i1++)
        cout<<array[i1]<<" ";
    cout<<endl ;

}

void dfs_util(TreeNode *node1 , vector<int>array ,int &ans1)
{
    if(node1->left==NULL &&  node1->right==NULL)
    {
        //leaf node
        array[node1->val]++ ;

        bool onlyoneodd = true ;
        for (int i1 = 1; i1 < 10; i1++)
            if(array[i1]%2!=0 && onlyoneodd)
                onlyoneodd = false ;
            else if(array[i1]%2!=0)
                return ;

        ans1++ ;
        return ;
    }

    array[node1->val]++ ;
    if(node1->left!=NULL)
        dfs_util(node1->left , array , ans1 );

    if(node1->right!=NULL)
        dfs_util(node1->right , array , ans1 );

}
int pseudoPalindromicPaths (TreeNode* root) 
{
    if(root==NULL)
        return 0 ;
    int ans1 = 0 ;
    vector<int> array(10,0);
    dfs_util(root , array , ans1);
    return ans1 ;


}




int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,m;//, target;
    testcase=1 ;
    // cin>>testcase;
    while (testcase--)
    {
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(3);
        root->right = new TreeNode(1);        

        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(1);

        root->right->right = new TreeNode(1);        

        cout<<pseudoPalindromicPaths(root)<<endl;

    }
    return 0 ;
}






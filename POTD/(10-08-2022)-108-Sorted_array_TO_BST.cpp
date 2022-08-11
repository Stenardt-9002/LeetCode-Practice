

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



TreeNode* convert_util(vector<int>nums , int start , int end)
{

    if(start==end)
        return new TreeNode(nums[start]);
    if(start>end||end>=nums.size())
        return NULL ;

    int mid = (start+end)>>1;

    TreeNode *cur =new TreeNode(nums[mid]);
    cur->left = convert_util(nums,start , mid-1);
    cur->right = convert_util(nums, mid+1, end);

    return cur ;

}



TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    int n= nums.size();
    TreeNode* ans1 = convert_util(nums , 0 , n-1);
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
    long long int n,a,b;
    testcase=1 ;
    while (testcase--)
    {
        cin>>n>>a>>b ;

    }
    return 0 ;
}




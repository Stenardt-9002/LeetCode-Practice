// https://leetcode.com/problems/n-ary-tree-level-order-traversal/







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



vector<vector<int>> levelOrder(Node* root) 
{
        if(root==NULL)
        return {};    
        queue<Node*> q1;
        vector<vector<int>> ans1 ;
        q1.push(root);
        while (!q1.empty())
        {
            vector<int> onelevel ;
            int n = q1.size();
            while(n--)
            {    
                Node *frontnode = q1.front()    ;
                q1.pop();
                for(auto x : frontnode->children)
                    q1.push(x);
                onelevel.push_back(frontnode->val);
            }
            ans1.push_back(onelevel);
        }

        return ans1 ;
}







// int main(int argc, char const *argv[])
// {
//     fastIO

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output1.txt","w",stdout);
//     #endif 


//     int testcase ;
//     int n ,m;//, target;
//     // testcase=2 ;
//     cin>>testcase;
//     while (testcase--)
//     {
//         cin>>n ;
//         vector<vector<string>> input1 ;
//         while(n--)
//         {
//             string name ; 
//             cin>>name ;
//             vector<string> intup ;
//             intup.push_back(name);
//             int noofemails ; 
//             cin>> noofemails ;
//             while(noofemails--)
//             {
//                 cin>>name ;
//                 intup.push_back(name);
//             }
//             input1.push_back(intup);
//         }
        
//         vector<vector<string>> output1 = mergeDetails(input1);
//         for (auto vec : output1)
//         {
//             for(auto str : vec)
//                 cout<<str<<" ";

//             cout<<endl ;
//         }
        


//     }
//     return 0 ;
// }










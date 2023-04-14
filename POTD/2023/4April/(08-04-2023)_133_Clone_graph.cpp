// https://leetcode.com/problems/clone-graph/







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






class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL)
            return NULL ;
        unordered_map<Node* ,Node*> map_1;
        Node *ans = new Node(node->val);
        map_1[node] = ans ;
        //bfs 
        queue<Node*>qoriginal ;
        qoriginal.push(node);
        
        while(!qoriginal.empty())
        {
            int n = qoriginal.size();
            for(int i = 0 ; i<n;i++)
            {
                Node *orig = qoriginal.front();
                qoriginal.pop();
                for(auto child : orig->neighbors)
                {
                    if(map_1.find(child)==map_1.end())
                    {
                        map_1[child] = new Node(child->val);
                        qoriginal.push(child);
                    }
                    
                    map_1[orig]->neighbors.push_back(map_1[child]);
                    
                }
            }
        }

        return ans ; 

    }
};
























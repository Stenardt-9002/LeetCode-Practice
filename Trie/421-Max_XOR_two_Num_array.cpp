// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/




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

const long long int mod2 =  1e18 ;



class Node
{
    public:
    Node *links[2] ;

    Node *get(int val)
    {
        return this->links[val];
    }
    void put(int key , Node* node)
    {
        this->links[key] = node ;
    }
    bool containskey(int val)
    {
        return (this->links[val])!=NULL ;
    }
};



class Trie 
{
    public:
    Node *root ;
    Trie()
    {
        root = new Node() ;
    }
    void insert(int num)
    {
        Node *temp = root ;
        for(int i1 = 31;i1>=0;i1--)
        {
            int val = (num>>i1)&1;
            if(!temp->containskey(val))
                temp->put(val , new Node())    ;

            temp = temp->get(val);
        }
    }
    int max_xor_val(int num)
    {
        int ans1 = 0;
        Node *temp = root ;
        for(int i1 = 31;i1>=0;i1--)
        {
            int val = (num>>i1)&1;
            if(temp->containskey(1-val))
            {
                temp = temp->get(1-val);//   temp->put(val , new Node())    ;
                ans1 |= (1<<i1);
            }
            else 
            temp = temp->get(val);
        }
        return ans1 ;
    }

};







int findMaximumXOR(vector<int>& nums) 
{
    int n = nums.size()    ;
    int final_ans1 = 0 ;
    Trie *newroot = new Trie();
    // for (int i1 = 0; i1 < n; i1++)
    // newroot->insert(nums[i1]);
    for (int i1 = 1; i1 < n; i1++)
    {
        final_ans1 = max(final_ans1 , newroot->max_xor_val(nums[i1]))        ;
        newroot->insert(nums[i1]);
    }
    
    return final_ans1 ;
}


















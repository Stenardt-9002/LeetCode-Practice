// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/









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

class Node{
    public :
    int num_ins =0;
    Node *links[10] = {};
    bool isanum = false ;
    Node *get(int num)
    {
        return this->links[num];
    }
    bool containskey(int num)
    {
        return (this->links[num])!=NULL ;
    }
    void put(int num , Node *node)
    {
        this->links[num] = node ;
    }
    void increase_prefix()
    {
        this->num_ins++ ;
    }

};


class Trie
{
    public: 
    Node *root ;
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        float number_dig = log10(num);
        int digits = floor(number_dig)+1 ;
        Node* temp = root;
        for (int j1 = digits-1; j1 >=0; j1--)
        {
            int dividend = num/pow(10,j1);
            if(!temp->containskey(dividend))
                temp->put(dividend, new Node());
            
            temp = temp->get(dividend);
            temp->increase_prefix();
            // cout<<"DEBUG "<<num ;
            num -= (dividend*pow(10,j1));
        }
        temp->isanum = true ;
    }
    // void recursive(Node *curnode , int current_ans ,int &ans1)
    // {
    //     if(curnode==NULL)
    //         return ;
    //     if(curnode->isanum)
    //         // ans1.push_back(current_ans);
    //     current_ans*=10 ;
    //     for (int  nextnum = 0; nextnum < 10; nextnum++)
    //         recursive(curnode->get(nextnum) , current_ans+nextnum , ans1);

    // }
    int all_numbers(int k)
    {
        Node* temp = root ;
        int ans1 ;
        int sum_to_now = 0,start;
        for (start = 1; start < 10 && sum_to_now<k; start++)
        {
            sum_to_now+=root->get(start)->num_ins;
            recursive(root->get(start),start,ans1);
        }
        
        return ans1 ;
    }

};









vector<int> lexicalOrder(int n) 
{
    Trie *root = new Trie();
    for (int i1 = 1; i1 <=n; i1++)
        root->insert(i1);

    return root->all_numbers();    
}


int findKthNumber(int n, int k) 
{
    Trie *root = new Trie();
    for (int i1 = 1; i1 <=n; i1++)
        root->insert(i1);

    return root->all_numbers()[k-1];    
}










































////a much better solution 



class Solution {
public:
    int findKthNumber(int n, int k) 
    {
        int ans1 = 1;
        for (int i = 0; i < k; i++) 
        {
            if (ans1 * 10 <= n) 
                ans1 *= 10;
            else 
            {
                if (ans1 >= n) 
                    ans1 /= 10;
                ans1 += 1;
                while (ans1 % 10 == 0)
                    ans1 /= 10;
            }
        }
        return ans1;
    }
};

    int findKthNumber(long int n,long int k) 
    {
        long int ans1 = 1;
        for (long int i = 0; i < k-1; i++) 
        {
            if (ans1 * 10 <= n) 
                ans1 *= 10;
            else 
            {
                if (ans1 >= n) 
                    ans1 /= 10;
                ans1 += 1;
                while (ans1 % 10 == 0)
                    ans1 /= 10;
            }
        }
        return ans1;  
    }


// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
















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
















class Node{
    public:
    Node* links[26];
    bool flag = false ;

    bool containskey(char ch)
    {
        return this->links[ch-'a']!=NULL ;


    }



    void put(char ch , Node* node)
    {
        this->links[ch-'a']=node ;
    }
    Node* get(char ch)
    {
        return this->links[ch-'a'];
    }
    void setEnd()
    {
        this->flag = true ;
    }
    bool isEnd()
    {
        return this->flag ;
    }

};





class Trie {
public:
    Node* root ;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node *temp = this->root ;
        for(int i = 0 ; word[i] ; i++)    
        {
            if(!temp->containskey(word[i]))
                temp->put(word[i] , new Node());
            temp = temp->get(word[i]) ;
            
        }
        temp->setEnd();
    }
    
    bool search(string word) 
    {
        Node* temp = this->root ;
        for(int i = 0 ; word[i] ; i++)    
        {
            if(!temp->containskey(word[i]))
                return false;
            temp = temp->get(word[i]) ;
            
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        Node* temp = this->root ;
        for(int i = 0 ; prefix[i] ; i++)    
        {
            if(!temp->containskey(prefix[i]))
                return false;
            temp = temp->get(prefix[i]) ;
            
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/



















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












class Node
{
    public: 
    bool end_flag= false ;
    Node* links[26] ;
    bool containskey(char ch)
    {
        return this->links[ch-'a']!=NULL ;
    }
    void put(char ch , Node *newnode)
    {
        this->links[ch-'a'] = newnode ;
    }
    Node* get(char ch)
    {
        return this->links[ch-'a'] ;
    }
    void setend()
    {
        this->end_flag = true ;
    }
    bool getend()
    {
        return this->end_flag ;
    }
};










class Trie {
public:
    Node* root ;
    Trie() {
        root = new Node();
    }
    
    void addWord(string word) 
    {
        Node* trav = this->root ;
        for (int i = 0; word[i]; i++)
        {
            if(!trav->containskey(word[i]))
                trav->put(word[i],new Node());

            trav = trav->get(word[i]);
        }
        trav->setend();
    }
    
    bool search(string word , Node* curpos) 
    {
        bool result = false ;
        for (int i = 0; word[i]; i++)
        {
            if(word[i]=='.')
            {
                result = false ;
                for (int ch = 'a'; ch <='z'; ch++)
                    if(curpos->containskey(ch))
                        result = result||this->search(word.substr(i+1 , word.length()) ,curpos->get(ch) ) ;

                    return result ;
                

            }
            if(!curpos->containskey(word[i]))
                return false ;
            curpos = curpos->get(word[i]);
        }
        return curpos->getend();
    }
};












class WordDictionary 
{
public:
    Trie* mainnode ;
    WordDictionary() {
        mainnode = new Trie()    ;
    }
    
    void addWord(string word) {
        mainnode->addWord(word);
    }
    
    bool search(string word) {
        return mainnode->search(word , mainnode->root);
    }
};

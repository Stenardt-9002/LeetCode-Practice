

// https://leetcode.com/problems/implement-magic-dictionary/










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
    public : 
    Node* links[26];
    bool end_fl = false ;
    bool contatinsKey(char ch)
    {
        return this->links[ch-'a']!=NULL ;
    }
    void put(char ch , Node *newconnect)
    {
        this->links[ch-'a'] = newconnect;
    }
    Node *get(char ch)
    {
        return this->links[ch-'a'];
    }
    void end()
    {
        this->end_fl = true ;
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
        void insert(string word )
        {
            Node *trav = root ;
            for (int i1 = 0; word[i1]; i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    trav->put(word[i1] , new Node());

                trav = trav->get(word[i1]);
            }
            trav->end();
        }
        
        bool native_search(string word )
        {
            Node *trav = root ;
            for (int i1 = 0; word[i1]; i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    return false ;

                trav = trav->get(word[i1]);
            }
            return trav->end_fl ;
        }
        

};






class MagicDictionary {
public:
    Trie *root;
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) 
    {
        for(auto word:dictionary)    
            root->insert(word);
    }
    
    bool search(string searchWord) 
    {
        for (int i1 = 0; searchWord[i1]; i1++)
        {
            char c= searchWord[i1];
            for (int ch = 'a'; ch <='z'; ch++)
            {
                if(ch==c)
                    continue ;

                searchWord[i1] = ch;
                if(root->native_search(searchWord))
                    return true ;
            }
            
            searchWord[i1] = c;
        }
        return false ;
    }
};













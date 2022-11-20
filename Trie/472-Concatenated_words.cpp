// https://leetcode.com/problems/concatenated-words/








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
            for(int i1 = 0; word[i1];i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    return false ;
                trav = trav->get(word[i1]);
            }
            return trav->end_fl;
        }


        // bool search(string word,vector<string>current_stack , vector<vector<string>>&final_ans)
        // {
        //     if(word=="")
        //     {
        //         final_ans.push_back(current_stack);
        //         return true ;
        //     }
        //     Node *trav = root ;
        //     bool ans1 = false ;            
        //     int len1 = word.length();
        //     string current_string = "";
        //     for (int i1 = 0; i1<len1; i1++)
        //     {
        //         if(!trav->contatinsKey(word[i1]))
        //             break;

        //         trav = trav->get(word[i1]);
        //         current_string+=word[i1];
        //         if(trav->end_fl)
        //         {
        //             current_stack.push_back(current_string);
        //             bool temp = (this->search(word.substr(i1+1,len1-i1-1) ,current_stack , final_ans));
        //             ans1 = ans1||temp ;
        //             current_stack.pop_back();
        //         }

        //     }
        //     return ans1 ;
        // }
        
        bool search(string word,vector<string>current_stack ,bool &final_ans)
        {
            if(word=="")
            {
                if(current_stack.size()>=2)
                    final_ans = true ;
                return true ;
            }
            Node *trav = root ;
            bool ans1 = false ;            
            int len1 = word.length();
            string current_string = "";
            for (int i1 = 0; i1<len1; i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    break;

                trav = trav->get(word[i1]);
                current_string+=word[i1];
                if(trav->end_fl)
                {
                    current_stack.push_back(current_string);
                    bool temp = (this->search(word.substr(i1+1,len1-i1-1) ,current_stack , final_ans));
                    ans1 = ans1||temp ;
                    current_stack.pop_back();
                }
                //end unction early
                if(final_ans)
                    return true ;
            }
            return ans1 ;
        }
};








    


    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        Trie *root = new Trie();
        for(auto word : words)
            root->insert(word);

        vector<string> ans1 ;
        for(auto word : words)
        {
            bool ans = false ;
            vector<string> stack ;
            root->search(word,stack,ans);
            if(ans)
                ans1.push_back(word);
        }

        return ans1 ;        
    }
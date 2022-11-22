// https://leetcode.com/problems/replace-words/



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
        

        void get_prefix(string word,string &ans1 )
        {
            Node *trav = root ;
            ans1 = "";
            for(int i1 = 0; word[i1];i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                {
                    ans1 = word;
                    return ;
                }
                trav = trav->get(word[i1]);
                ans1+=word[i1];
                if(trav->end_fl)
                    return  ;
            }
            return ;
        }
        // void get_prefix(string word,string &ans1 )
        // {
        //     Node *trav = root ;
        //     ans1 = "";
        //     for(int i1 = 0; word[i1];i1++)
        //         if(trav->contatinsKey(word[i1]))
        //         {
        //             trav = trav->get(word[i1]);
        //             ans1+=word[i1];
        //             if(trav->end_fl)
        //                 return  ;
        //         }
        //         else 
        //             break;
            
        //     ans1 = word;
        // }
};





string replaceWords(vector<string>& dictionary, string sentence) 
{
    std::stringstream ss(sentence);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> words(begin, end);
    Trie *root = new Trie();
    for(auto word : dictionary)
        root->insert(word);
    string ans = "";
    for(auto word : words)
    {
        string temp = "";
        root->get_prefix(word , temp);
        ans+=temp ;
        ans+=" ";
    }
    ans.pop_back();

    return ans ;

}

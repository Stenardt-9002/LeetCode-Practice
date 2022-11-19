// https://leetcode.com/problems/word-break-ii/












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
        void insert(string word)
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


        bool search(string word,vector<string>current_stack , vector<vector<string>>&final_ans)
        {
            if(word=="")
            {
                final_ans.push_back(current_stack);
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

            }
            return ans1 ;
        }
};









vector<string> wordBreak(string s, vector<string>& wordDict) 
{
        Trie *root = new Trie();
        for(auto x: wordDict)
            root->insert(x);
        vector<string> stack ;
        vector<vector<string>>ans;
        bool abs =  root->search(s,stack , ans);
        if(!abs)
            return {};
        vector<string> final_ans ;
        for(auto v:ans)
        {

            string temp1 = "";
            for(auto s:v)
            {
                temp1+=s;
                temp1+=" ";
            }
            temp1.pop_back();
            final_ans.push_back(temp1);
        }
    return final_ans;
}


int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n ;
        string s ; 
        cin>>s ;

        cin>>n ;
        vector<string> wordDict(n) ;
        for (int i1 = 0; i1 < n; i1++)
            cin>>wordDict[i1];

        vector<string> ans1 = wordBreak(s, wordDict);
        for(auto v: ans1)
            cout<<v<<"\n";
        
    }
    

    return 0;
}






































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
        void insert(string word)
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
        


        bool search(string word,vector<string>current_stack , vector<vector<string>>&final_ans)
        {
            if(word=="")
            {
                final_ans.push_back(current_stack);
                return true ;
            }
            Node *trav = root ;
            bool ans1 = false,temp ;            
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
                    temp = (this->search(word.substr(i1+1,len1-i1-1) ,current_stack , final_ans));
                    ans1 = ans1||temp ;
                    current_stack.pop_back();//now no longer part of stack
                }

            }
            return ans1 ;
        }
};









vector<string> wordBreak(string s, vector<string>& wordDict) 
{
    Trie *root = new Trie();
    for(auto x: wordDict)
        root->insert(x);//save all words
    vector<string> stack ;//maintain the words break points
    vector<vector<string>>ans;
    bool abs =  root->search(s,stack , ans);
    if(!abs)//no such string possible
        return {};
    vector<string> final_ans ;
    for(auto v:ans)
    {

        string temp1 = "";
        for(auto s:v)
        {
            temp1+=s;
            temp1+=" ";
        }
        temp1.pop_back();//remove last whitespace
        final_ans.push_back(temp1);// add to answer
    }
    return final_ans;
}




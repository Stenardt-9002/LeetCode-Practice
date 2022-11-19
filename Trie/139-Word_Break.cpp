// https://leetcode.com/problems/word-break/











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


        bool search(string word)
        {
            if(word=="")
            return true ;
            Node *trav = root ;
            bool ans1 = false ;            
            int len1 =word.length();
            // cout<<"Debug 2 "<<word<<endl;
            for (int i1 = 0; i1<len1; i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    break;

                trav = trav->get(word[i1]);
                // cout<<"DEug1 "<<word[i1];
                if(trav->end_fl)
                    ans1 = ans1||(this->search(word.substr(i1+1,len1-i1-1)));

            }
            // cout<<"DEbug 1";
            return ans1 ;
            //first if false means no such sentence ending with no letter
            //second means word ending
        }
};









// bool wordBreak(string s, vector<string>& wordDict) 
// {
//         Trie *root = new Trie();
//         for(auto x: wordDict)
//             root->insert(x);


//         // cout<<root->search(s)<<endl;
//         return root->search(s);
// }


//improved 
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if(wordDict.size()==0)
            return false ;
        Trie *root = new Trie();
        for(auto x: wordDict)
            root->insert(x);

        int len1 = s.size();
        string temp_word_sec ;
        vector<bool> dp1(len1+1 , false);
        dp1[0] = true ;
        for (int i1 = 1; i1 <=len1; i1++)
            for (int j1 = i1-1; j1 >=0; --j1)
                if(dp1[j1])
                {
                    temp_word_sec = s.substr(j1,i1-j1);//next section
                    if(root->native_search(temp_word_sec))
                    {
                        dp1[i1] = true ;
                        break ;//frist loop
                    }
                }



        return dp1[len1];
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

        cout<<wordBreak(s, wordDict)<<endl;
    }
    

    return 0;
}






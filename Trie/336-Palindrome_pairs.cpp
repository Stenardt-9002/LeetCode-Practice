// https://leetcode.com/problems/palindrome-pairs/











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


bool checkifpallindrome(string word1 , int start , int end)
{
    while(start<=end && word1[start]==word1[end])
        start++ , end-- ;

    return start>=end ;
}
class Node
{
    public:
    Node *links[26] = {};
    int cur_indx = -1;
    vector<int> palindrome_index = {};
    Node *get(char key)
    {
        return this->links[key-'a'];
    }
    void put(char key , Node *node)
    {
        this->links[key-'a'] = node;
    }
    bool containkey(char key)
    {
        return ((this->links[key-'a'])!=NULL);
    }
    
};


class Trie 
{
    public:
    Node *root = new Node();
    void insert(string s , int index)
    {
        Node *temp = root ;
        int j = s.size();
        while(--j)
        {

            if(!temp->containkey(s[j]))
                temp->put(s[j],new Node());
                
            if(checkifpallindrome(s,0,j))
                temp->palindrome_index.push_back(index);
            temp = temp->get(s[j]);
        }
        temp->cur_indx = index ;
        temp->palindrome_index.push_back(index);
    }

    void search(vector<string> words , int index , vector<vector<int>>&ans1 )
    {
        Node *temp = root ;
        for(int j1 = 0 ; j1<words[index].size();j1++)
        {

            if(temp->cur_indx>=0 && temp->cur_indx!=index && checkifpallindrome(words[index],j1,words[index].size()-1))
                ans1.push_back({index,temp->cur_indx});

            temp  = temp->get(words[index][j1]);
            if(temp==NULL)
                return ;

        }
        for(int j:temp->palindrome_index)
        {
            if(index==j)
                continue ;
            ans1.push_back({index , j});
        }
    }



};






vector<vector<int>> palindromePairs(vector<string>& words) 
{
    int n = words.size();
    vector<vector<int>> ans1 ;


    Trie *mainroot = new Trie();
    for (int i1 = 0; i1 < n; i1++)
        mainroot->insert(words[i1],i1);

    for (int i1 = 0; i1 < n; i1++)
        mainroot->search(words , i1 , ans1) ;



    return ans1 ;
}














// struct TrieNode 
// {
//     TrieNode *next[26] = {};
//     int index = -1;
//     vector<int> palindromeIndexes;
// };

// class Solution 
// {
//     TrieNode *root; 
//     void add(string s, int i) 
//     {
//         TrieNode* node = root;
//         for (int j = s.size() - 1; j >= 0; --j) 
//         {
//             if (checkifpallindrome(s, 0, j)) 
//                 node->palindromeIndexes.push_back(i); // A[i]'s prefix forms a palindrome

//             if (!node->next[s[j] - 'a']) 
//                 node->next[s[j] - 'a'] = new TrieNode();
//             node = node->next[s[j] - 'a'];
//         }
//         node->index = i;
//         node->palindromeIndexes.push_back(i); // A[i]'s prefix is empty string here, which is a palindrome.
//     }
    
    
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) 
//     {
//         int n = words.size();
//         for (int i = 0; i < n; ++i) 
//             add(words[i], i);
//         vector<vector<int>> ans;
//         for (int i = 0; i < n; ++i) 
//         {
//             string s1 = words[i];
//             TrieNode* node = root;
//             for (int j = 0; j < s1.size() && node; ++j) 
//             {
//                 if (node->index != -1 && node->index != i && checkifpallindrome(s1, j, s1.size() - 1)) 
//                     ans.push_back({ i, node->index }); 
                
//                 node = node->next[s1[j] - 'a'];
//             }
//             if (!node) 
//                 continue;
            
            
//             for (int j : node->palindromeIndexes) 
//                 if (i != j) 
//                     ans.push_back({ i, j });
//         }
//         return ans;
//     }
// };








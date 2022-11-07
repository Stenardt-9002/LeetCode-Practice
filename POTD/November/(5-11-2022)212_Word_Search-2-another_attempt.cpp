

// https://leetcode.com/problems/word-search-ii/








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

struct Node_T 
{
    Node_T* links[26] = {};
    string* word;
    void addWord(string& word) 
    {
        Node_T* cur = this;
        for (char c : word) 
        {
            c -= 'a';
            if (cur->links[c] == nullptr) 
                cur->links[c] = new Node_T();
            cur = cur->links[c];
        }
        cur->word = &word;
    }
};

class Solution 
{
public:
    int m, n;
    int DIR[5] = {0, 1, 0, -1, 0};
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        m = board.size(); n = board[0].size();
        Node_T trieNode;
        for (string& word : words) trieNode.addWord(word);
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, &trieNode);
        return ans;
    }
    void dfs(vector<vector<char>>& board, int r, int c, Node_T* cur) 
    {
        if (r < 0 || r == m || c < 0 || c == n || board[r][c] == ' ' || cur->links[board[r][c]-'a'] == nullptr) 
            return;
        char orgChar = board[r][c];
        cur = cur->links[orgChar - 'a'];
        if (cur->word != nullptr) 
        {
            ans.push_back(*cur->word);
            cur->word = nullptr; 
        }
        board[r][c] = ' '; 
        for (int i = 0; i < 4; ++i) 
            dfs(board, r + DIR[i], c + DIR[i+1], cur);
        board[r][c] = orgChar; 
    }
};




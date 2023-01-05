

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



// bool dfs_util(vector<vector<char>> board , vector<vector<bool>>&visisted , string current ,int i1 , int j1, int n , int m , int curr_index)
// {

//     if(i1<0||j1<0||i1>=n||j1>=m||visisted[i1][j1]||board[i1][j1]!=current[curr_index])
//         return false ;
//     if(current.size()-1==curr_index)
//         return board[i1][j1] == current[curr_index];

//     bool ans1 = true ;
//     visisted[i1][j1] = true ;
//     ans1 = dfs_util(board , visisted , current , i1+1 ,j1 , n ,m , curr_index+1)||
//     dfs_util(board , visisted , current , i1-1 ,j1 , n ,m , curr_index+1)||
//     dfs_util(board , visisted , current , i1 ,j1+1 , n ,m , curr_index+1)||
//     dfs_util(board , visisted , current , i1 ,j1-1 , n ,m , curr_index+1) ;

//     visisted[i1][j1] = false  ;

//     return ans1 ;
// }


// vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
// {
//         vector<string> ans1 ;
//     int n = board.size();
//     int m = board[0].size();
//     vector<vector<bool>>visited(n,vector<bool>(m,false));

//     for (auto str1: words)
//         for (int i1 = 0; i1 < n; i1++)
//             for (int j1 = 0; j1 < m; j1++)
//                 if(str1[0]==board[i1][j1] && dfs_util(board,visited ,str1,i1,j1,n,m,0))
//                     ans1.push_back(str1),i1=n,j1=m;

//     return ans1 ;
// }


class Node {
    public:
    Node *links[26];
    int countendwith = 0 ;
    int countwithprefix = 0 ;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL) ;
    }
    void put(char ch , Node *node)
    {
        links[ch-'a'] = node ;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    } 
    void increaseEnd()
    {
        countendwith++ ;
    }
    void increasePrefix()
    {
        countwithprefix++ ;
    }
    void deleteEnd()
    {
        countendwith-- ;
    }
    void reducePrefix()
    {
        countwithprefix--;
    }

};


class Trie {
public:

    Node* root  ;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                node->put(word[i1] , new Node());

            node = node->get(word[i1]);//moving to refrence trie
            node->increasePrefix();
        }
        node->increaseEnd();//set end 
        
    }
    
    int countWordsEqualTo(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                return 0;

            node = node->get(word[i1]);
        }
        return node->countendwith ;
    }
    int countWordStartingWith(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                return 0;

            node = node->get(word[i1]);
        }
        return node->countwithprefix ;
    }
//     void erase(string word) 
//     {
//         //asumming the word exist
//         Node *node = root ;
//         for (int i1 = 0; word[i1]; i1++)
//         {
//             if(!node->containsKey(word[i1]))
//                 return ;

//             node = node->get(word[i1]);//moving to refrence trie
//             node->reducePrefix();
//         }
//         node->deleteEnd();//set end 
        
//     }
    void erase(string word) 
    {
        //asumming the word exist
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                return ;
            if(node->get(word[i1])->countwithprefix==1)
            {
                node->put(word[i1] ,NULL );
                return ;
            }
            node = node->get(word[i1]);//moving to refrence trie
            node->reducePrefix();
        }
        node->deleteEnd();//set end 
        //removing links
        

    }
    
};




void tweaked_dfs_util(vector<vector<char>> board , vector<vector<bool>>&visisted ,set<string>&ans_set,Node* centralnode, string current ,int i1 , int j1, int n , int m )
{

    if(i1<0||j1<0||i1>=n||j1>=m||visisted[i1][j1])
        return ;

    if(centralnode->containsKey(board[i1][j1]) )
    {
        current+=board[i1][j1];
        centralnode = centralnode->get(board[i1][j1]);
        if(centralnode->countendwith>0)
            ans_set.insert(current);
        
        
        visisted[i1][j1] = true ;
        tweaked_dfs_util(board , visisted ,ans_set,centralnode, current , i1+1 ,j1 , n ,m  );
        tweaked_dfs_util(board , visisted ,ans_set,centralnode, current , i1-1 ,j1 , n ,m  );
        tweaked_dfs_util(board , visisted ,ans_set,centralnode, current , i1 ,j1+1 , n ,m  );
        tweaked_dfs_util(board , visisted ,ans_set,centralnode, current , i1 ,j1-1 , n ,m  );

        visisted[i1][j1] = false  ;
        
    }
}





vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    set<string> ans_set ;

    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    Trie* trieroot = new Trie();
    for (auto str1: words)
        trieroot->insert(str1);

    Node* centralnode = trieroot->root ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
        {
            set<string> current_set ;
            tweaked_dfs_util(board,visited,current_set,centralnode ,"",i1,j1,n,m);
            for(auto inserted_str : current_set)
            {
                trieroot->erase(inserted_str);
                ans_set.insert(inserted_str);
            }
            centralnode = trieroot->root ;
        }

    // void tweaked_dfs_util(vector<vector<char>> board , vector<vector<bool>>&visisted ,set<string>&ans_set,Node* centralnode, string current ,int i1 , int j1, int n , int m )
    vector<string> ans1(ans_set.begin(),ans_set.end());

    return ans1 ;
}







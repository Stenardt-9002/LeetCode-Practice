// https://leetcode.com/problems/substring-with-concatenation-of-all-words/





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
// {
//     // BFS on path
//     unordered_set<string>WordLsit ;
//     for(auto x : wordList)
//         WordLsit.insert(x);

//     WordLsit.insert(endWord);
//     vector<vector<string>>ans1 ;
//     queue<vector<string>> paths ;

//     int level = 1 ; 
//     int foundfirst = INT_MAX ;


//     unordered_set<string> visited_words ;

//     while (!paths.empty())
//     {
//         vector<string> frontpath = paths.front();
//         paths.pop();
//         if(frontpath.size()>level)
//         {
//             for(string w:visited_words)
//                 WordLsit.erase(w);
//             visited_words.clear();
//             if(frontpath.size()>foundfirst)
//                 break ;
//             else 
//                 level = frontpath.size();
//         }


//         string last = frontpath.back();



//         //find next words in wordlsit 
//         for (int i1 = 0; i1 < last.size(); i1++)
//         {
//             string newword = last ;
//             for (char  c1 = 'a'; c1  <= 'z'; c1 ++)
//             {
//                newword[i1] = c1 ;
//                if(WordLsit.find(newword)!=WordLsit.end())
//                {
//                     vector<string> newpath = frontpath ;
//                     newpath.push_back(newword);
//                     visited_words.insert(newword);
//                     if(newword==endWord)
//                     {
//                         foundfirst = level ;
//                         ans1.push_back(newpath);
//                     }
//                     else 
//                         paths.push(newpath);
//                }
//             }
//         }
//     }
//     return ans1 ;
// }
void dfs_util(string beginWord ,string endWord ,unordered_map<string,unordered_set<string>> &adj ,vector<string> &path,vector<vector<string>> &ans1)//all possible path of fix length
{
    path.push_back(beginWord);
    if(beginWord == endWord)
    {
        ans1.push_back(path);
        path.pop_back();
        return  ;
    }
    for(auto x : adj[beginWord])
        dfs_util(x,endWord,adj,path,ans1);

    path.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
    vector<vector<string>>ans1 ;

    //first get min depth ::Word Ladder 1 
    unordered_map<string,unordered_set<string>> adj ; //graph 
    unordered_set<string> newWordlist(wordList.begin(),wordList.end());



    //get min depth 
    queue<string> q1 ;
    q1.push(beginWord);
    unordered_map<string,int> visisted ;
    visisted[beginWord] = 0 ;
    while (!q1.empty())
    {
        string frontstr = q1.front()     ;
        q1.pop();
        string allpossible = frontstr ;
        for (int allc = 0; allc < frontstr.size(); allc++)
        {
            for (char c1 = 'a'; c1 <= 'z'; c1++)
            {
                if(allpossible[allc]==c1)
                    continue ; //orginal
                allpossible[allc]==c1;

                if(newWordlist.count(allpossible)>0)
                {
                    if(visisted.count(allpossible))
                    {
                        visisted[allpossible] = visisted[frontstr]+1;//child 
                        q1.push(allpossible);
                        adj[frontstr].insert(allpossible);
                    }
                    else if(visisted[allpossible]==visisted[frontstr]+1)
                        adj[frontstr].insert(allpossible);

                }
                
            }
            allpossible[allc] = frontstr[allc];//original
        }
    }
    

    vector<string> path ;
    dfs_util(beginWord , endWord , adj , path,ans1);//all possible path of fix length
    return ans1 ;
}















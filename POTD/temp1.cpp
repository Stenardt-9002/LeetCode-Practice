// https://leetcode.com/problems/substring-with-concatenation-of-all-words/





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




class Solution { // 4 ms, faster than 99.32%
public:
    vector<vector<string>> findLadders(const string& beginWord, const string& endWord, vector<string>& wordList) 
    {
        unordered_set<string> newWordsset(wordList.begin(), wordList.end()); 
        newWordsset.erase(beginWord);

        unordered_map<string, vector<vector<string>>> adj;
        adj[beginWord] = {{beginWord}}; 
        while (!adj.empty()) {
            unordered_map<string, vector<vector<string>>> newgraph;
            for (const auto& [word, paths] : adj) 
            {
                if (word == endWord)
                    return adj[word]; 
                for (const string& nei : neighbors(word, newWordsset)) {
                    for (auto path : paths) {
                        path.push_back(nei);
                        newgraph[nei].push_back(path);
                    }
                }
            }
            for (const auto& [word, _] : newgraph) newWordsset.erase(word); 
            adj.swap(newgraph); 
        }
        return {};
    }
    vector<string> neighbors(const string& word, const unordered_set<string>& newWordsset) 
    {
        vector<string> ans;
        for (int i = 0; i < word.size(); ++i) { // change every possible single letters and check if it's in newWordsset
            for (char c = 'a'; c <= 'z'; ++c) {
                string newWord = word.substr(0, i) + c + word.substr(i+1);
                if (!newWordsset.count(newWord)) continue;
                ans.push_back(newWord);
            }
        }
        return ans;
    }
};



vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
        unordered_set<string> wordListnew;
        for(auto x: wordList)
            wordListnew.insert(x);
        queue<vector<string>> paths;
        vector<vector<string>> ans;
        wordListnew.insert(endWord);
        paths.push({beginWord});
        int level = 1;
        int minLevel = INT_MAX;
        

        unordered_set<string> visited; 
        
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                //reach a new level
                for (string w : visited) wordListnew.erase(w);
                visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            string last = path.back();
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (wordListnew.find(news) != wordListnew.end()) {
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }
        return ans;
    }


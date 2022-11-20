
// https://leetcode.com/problems/erect-the-fence/





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






class Solution {
public:
    int getRotationAngle(vector<int> first, vector<int> second, vector<int> third) 
    {
        return ((second[0] - first[0]) * (third[1] - first[1])) - ((second[1] - first[1]) * (third[0] - first[0]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) 
    {
        if (trees.size() <= 3) 
            return trees;
        
        sort(trees.begin(), trees.end());
        
        vector<vector<int>> answer1;
        answer1.push_back(trees[0]);
        answer1.push_back(trees[1]);
        for (int i = 2; i < trees.size(); i++) 
        {
            int lptr = answer1.size();
            while (answer1.size() >= 2 && getRotationAngle(answer1[lptr-2], answer1[lptr-1], trees[i]) > 0) 
            {
                answer1.pop_back();
                lptr--;
            }
            answer1.push_back(trees[i]);
        }
        
        vector<vector<int>> right_part;
        right_part.push_back(trees[trees.size() - 1]);
        right_part.push_back(trees[trees.size() - 2]);
        for (int i = trees.size() - 3; i >= 0; --i) 
        {
            int rptr = right_part.size(); 
            while (right_part.size() >= 2 && getRotationAngle(right_part[rptr-2], right_part[rptr-1], trees[i]) > 0) {
                right_part.pop_back();
                rptr--;
            }
            right_part.push_back(trees[i]);
        }
        
        answer1.pop_back();
        right_part.pop_back();
        for (int i = 0; i < right_part.size(); i++) 
            answer1.push_back(right_part[i]);
        
        
        sort(answer1.begin(), answer1.end());
        answer1.erase(std::unique(answer1.begin(), answer1.end()), answer1.end());
        
        return answer1;
    }
    
};
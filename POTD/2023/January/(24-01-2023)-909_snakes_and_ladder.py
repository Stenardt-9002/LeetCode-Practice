# // https://leetcode.com/problems/snakes-and-ladders/










# #include <bits/stdc++.h>
# #include<ext/pb_ds/tree_policy.hpp>
# #include<ext/pb_ds/assoc_container.hpp>


# using namespace std;
# using namespace __gnu_pbds ;
# typedef  long long int ll;
# #define DEBUG_var 1
# #define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


# const int mod1 = (1e9+7);
# const int MOD1 = 1000000007;








def snakesAndLadders(self, board):
    path_save = [1]
    dict_1 = {1: 0}
    n = len(board)
    for itr in path_save:
        for i in range(itr + 1, itr + 7):

            a, b = (i - 1) / n, (i - 1) % n

            nitrt = board[~a][b if a % 2 == 0 else ~b]
            if nitrt > 0:
                i = nitrt
            if i == n * n: 
                return dict_1[itr] + 1
            if i not in dict_1:
                dict_1[i] = dict_1[itr] + 1
                path_save.append(i)
    return -1






# class Solution {
# public:
#     int snakesAndLadders(vector<vector<int>>& board) {
        
#     }
# };
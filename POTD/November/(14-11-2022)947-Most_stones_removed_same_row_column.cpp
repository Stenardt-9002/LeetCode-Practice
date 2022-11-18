// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/









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



unordered_map<int, int> map1;
int islands = 0;

int find(int x) 
{
    if (!map1.count(x)) 
        map1[x] = x, islands++;
    if (x != map1[x]) 
        map1[x] = find(map1[x]);
    return map1[x];
}

void union1(int x, int y) 
{
    x = find(x), y = find(y);
    if (x != y) 
        map1[x] = y, islands--;
}





int removeStones(vector<vector<int>>& stones) 
{
    for (int i = 0; i < stones.size(); ++i)
        union1(stones[i][0], ~stones[i][1]);
    return stones.size() - islands;
}















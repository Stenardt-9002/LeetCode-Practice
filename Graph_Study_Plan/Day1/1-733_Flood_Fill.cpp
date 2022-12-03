// https://leetcode.com/problems/flood-fill/?envType=study-plan&id=graph-i










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





    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        short arrx[] = {-1,0,1,0,-1};
        short n = image.size();
        short m = image[0].size();
        short oldcolor = image[sr][sc]     ;
        queue<pair<short,short>> q1 ;
        if(color!=oldcolor)
            q1.push({sr,sc});
        while(!q1.empty())
        {
            pair<short,short> front_1 = q1.front();
            q1.pop();
            image[front_1.first][front_1.second] = color ;
            for(int i= 0;i<4;++i)
            {
                int newx = front_1.first+arrx[i];
                int newy = front_1.second+arrx[i+1];
                if(newx>=0 && newy>=0 && newx<n && newy<m && image[newx][newy]==oldcolor )
                    q1.push({newx , newy});
            }
            
        }
        return image ;
    }














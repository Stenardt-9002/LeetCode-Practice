// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/










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

// ll dfs_util(ll x1 ,ll y1 ,ll n,ll m,vector<vector<ll>> grid , vector<vector<ll>>&visited ,ll k,bool &reached_end)    
// {
//     if(x1<0 || y1<0 || x1>=n||y1>=m)
//         return INT_MAX ;
//     if(visited[x1][y1]!=-1)
//         return INT_MAX ;
//     // cout<<"\nDeug1 "<<x1<<" "<<y1<<endl;

//     visited[x1][y1]=1;
//     if(x1==n-1 && y1==m-1)
//     {
//         reached_end = true ;
//         return 0 ;
//     }



//     if(grid[x1][y1]==1 && k>0)
//         k-- ;
//     else if (grid[x1][y1]==1 && k<=0)
//         return INT_MAX ;

//     ll ans1 = 1+min({
//             dfs_util(x1+1 , y1 , n , m , grid , visited , k , reached_end),
//             dfs_util(x1-1 , y1 , n , m , grid , visited , k , reached_end),
//             dfs_util(x1 , y1+1 , n , m , grid , visited , k , reached_end),
//             dfs_util(x1 , y1-1 , n , m , grid , visited , k , reached_end)
//             });

//     visited[x1][y1]=-1;

//     return ans1 ;

// }



// ll shortestPath(vector<vector<ll>>& grid, ll k) 
// {
//     ll n = grid.size();
//     ll m = grid[0].size();
//     vector<vector<ll>> visited(n,vector<ll>(m,-1));
//     if(n==1 &&m==1 && k>0)
//         return 1 ;
//     else if(n==1 && m==1 && grid[0][0]==0)
//         return 1 ;
//     else if(n==1 && m==1 && grid[0][0]==1)
//         return -1 ;
//     bool reached_end = false ;
//     ll ans1 = INT_MAX ;
//     ans1 = dfs_util(0 , 0 ,n,m,grid , visited , k,reached_end)    ;
//     if(reached_end)
//         return ans1 ;
//     return -1 ;
// }























class Solution {
public:
    
    int bfs_util(vector<vector<int>>&matrix , int k ,int n , int m)
    {
        queue<tuple<int,int,int,int>> queue1 ;
        vector<vector<int>>visisted(n,vector<int>(m,-1))    ;
        int x1 ,y1 ,dis , curk ;

        queue1.push(make_tuple(0,0,0,k));
        while(!queue1.empty())
        {
            tuple<int,int,int,int> t1 = queue1.front();
            x1 = get<0>(t1);
            y1 = get<1>(t1);
            dis = get<2>(t1);
            curk = get<3>(t1);
            queue1.pop();
            if(x1<0||y1<0||x1>=n||y1>=m)
                continue ;

            //answer reached 
            if(x1==n-1&&y1==m-1)
                return dis;

            if(matrix[x1][y1]==1)//wall found
            {
                if(curk<=0)
                    continue ;
                curk-- ;
            }

            //NOT VISISTED 
            if(visisted[x1][y1]!=-1 && visisted[x1][y1]>=curk)//if better curk is not possible continue
                continue ;

            visisted[x1][y1] = curk ;//vsisted and curk is the better possibilty


            //queue push 4 direction 
            queue1.push(make_tuple(x1+1,y1,dis+1,curk));
            queue1.push(make_tuple(x1-1,y1,dis+1,curk));
            queue1.push(make_tuple(x1,y1+1,dis+1,curk));
            queue1.push(make_tuple(x1,y1-1,dis+1,curk));

        }

        return -1 ;
    }
    
    
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size()    ;
        int m = grid[0].size()    ;
        return bfs_util(grid,k,n,m);
    }
};






































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
        ll n ,m,k;
        cin>>n>>m>>k ;
        vector<vector<ll>>grid(n,vector<ll>(m,0));
        for (ll i1 = 0; i1 < n; i1++)
            for (ll j1 = 0; j1 < m; j1++)
                cin>>grid[i1][j1];
        // for (ll i1 = 0; i1 < n; i1++)
        //     for (ll j1 = 0; j1 < m; j1++)
        //         cout<<grid[i1][j1]<<" \n"[j1==m-1];
        // cout<<shortestPath(grid,k);
        cout<<endl;
    }
    

    return 0;
}






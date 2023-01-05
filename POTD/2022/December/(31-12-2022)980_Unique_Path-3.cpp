// https://leetcode.com/problems/unique-paths-iii/description/



















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







int arrx[] = {0,-1,0,1,0};
class Solution {
public:
    void dfs_util(int srcx,int srcy ,int n,int m ,int count ,int &ans ,vector<vector<int>>grid , vector<vector<bool>> &current_path ,vector<pair<int,int>>&path )
    {
        if(min(srcx ,srcy)<0 || srcx>=n || srcy>=m || current_path[srcx][srcy] || grid[srcx][srcy]==-1)
            return ;

        // cout<<srcx<<" "<<srcy<<endl;
        if(grid[srcx][srcy]==2||count==0)
        {
            if(count==0&&grid[srcx][srcy]==2)
            {
                ans++;
                cout<<"DEUX \n";
                for(auto [i,j] :path)
                    cout<<i<<" "<<j<<"    ";
                cout<<endl ;
            }
            return ;
        }
        current_path[srcx][srcy] = true ;
        path.push_back({srcx,srcy});
        for(int dir = 0 ;dir<4;++dir)
            dfs_util(srcx+arrx[dir] , srcy+arrx[dir+1] , n,m,count-1 , ans , grid , current_path,path);

        path.pop_back();
        current_path[srcx][srcy] = false ;
        return ;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        int srcx , srcy ;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                count+=(grid[i][j]==0);
                if(grid[i][j]==1)
                {
                    srcx = i ;
                    srcy = j ;
                }
            }

        int ans = 0 ;
        vector<vector<bool>>current_path(n,vector<bool>(m,false));
        vector<pair<int,int>>path;

        dfs_util(srcx+1,srcy,n,m ,count ,ans ,grid , current_path ,path);
        dfs_util(srcx,srcy+1,n,m ,count ,ans ,grid , current_path ,path);
        dfs_util(srcx-1,srcy,n,m ,count ,ans ,grid , current_path ,path);
        dfs_util(srcx,srcy-1,n,m ,count ,ans ,grid , current_path ,path);

        return ans ;      
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
        int m ,n;
        cin>>n>>m ;
        vector<vector<int>> input_vec(n,vector<int>(m,0)) ;
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
                cin>>input_vec[i][k];
        
        Solution obj1 ;
        obj1.uniquePathsIII(input_vec);
    }
    

    return 0;
}




























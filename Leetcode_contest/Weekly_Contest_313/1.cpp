


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


    int commonFactors(int a, int b) {
        int num  = gcd(a,b);   
    }

int sum_coordinate(int a , int b , vector<vector<int>> &grid)
{
    return grid[a][b]+grid[a][b+1]+grid[a][b+2]+grid[a+1][b+1]+grid[a+2][b]+grid[a+2][b+1]+grid[a+2][b+2];
}
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        int n = grid.size(); int m = grid[0].size(); 
        
        int ans1 = INT_MIN ;
        for (int i1 = 0; i1 < n-2; i1++)
            for (int j1 = 0; j1 < m-2; j1++)
                ans1 = max(ans1,sum_coordinate(i1,j1,grid));

        return ans1 ;    
    
        
    }
};
int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 

    int testcase ;
    long long int a,b ;//, target;
    testcase=1 ;
    // cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        int car = 0;
        cout<<endl;
    }
    return 0 ;
}




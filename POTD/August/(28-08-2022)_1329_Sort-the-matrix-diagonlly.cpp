// https://leetcode.com/problems/sort-the-matrix-diagonally/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);








vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
{
    int matsize = mat.size();
    int matcolsize = mat[0].size();
    vector<vector<int>> ans1(matsize , vector<int>(matcolsize , 0));

    for (int i1 = 0; i1 < matsize; i1++)
    {
        vector<int> temp1 ;
        for (int di = 0; i1+di<matsize && di<matcolsize; di++)
            temp1.push_back(mat[i1+di][di]);
            
        sort(temp1.begin(),temp1.end())        ;
        for (int di = 0; i1+di<matsize && di<matcolsize; di++)
            ans1[i1+di][di] = temp1[di];
        
    }
    

    for (int i1 = 0; i1 < matcolsize; i1++)
    {
        vector<int> temp1 ;
        for (int di = 0; i1+di<matcolsize  && di<matsize; di++)
            temp1.push_back(mat[di][i1+di]);
            
        sort(temp1.begin(),temp1.end())        ;
        for (int di = 0; i1+di<matcolsize  && di<matsize; di++)
            ans1[di][i1+di] = temp1[di];
        
    }
    return ans1 ;
}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    int intup, intcol ;
    while (testcase--)
    {
        cin>>intup>>intcol ;
        vector<vector<int>> rental(intup , vector<int>(intcol));
        for (int i1 = 0; i1 < intup; i1++)
            for (int j1 = 0; j1 < intcol; j1++)
                cin>>rental[i1][j1];

        vector<vector<int>> zans1 = diagonalSort(rental) ;
        for (auto vec : zans1)
        {
            for(auto ele : vec)
                cout<<ele<<" ";
            cout<<endl ;
        }
        
        cout<<endl;

    }
    return 0 ;
}


// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


int uniquePaths(int m, int n) 
{
    long long int mn2 = 1;
    long long int m1 = min(m,n);
    long long int n1 = max(m,n);

    for (int i1 = n1,j1=1; j1<m1 && i1 <= m+n-2; i1++,j1++)
        mn2*=i1 ,mn2/=j1;


    return mn2 ;

}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n ,m;
    cin>>n>>m ;

    int ans1 = uniquePaths(m,n);
    cout<<endl<<ans1 ;
    return 0 ;
}
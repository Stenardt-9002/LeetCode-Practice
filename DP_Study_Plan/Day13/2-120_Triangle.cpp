
// https://leetcode.com/problems/triangle/?envType=study-plan&id=dynamic-programming-i






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






int minimumTotal(vector<vector<int>>& triangle) 
{
    int n = triangle.size()        ;
    if(n==0)
        return 0 ;
    
    int sum1 = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        int cur_sum = sum1 ;
        sum1 = cur_sum+triangle[i][0];
        for (int j = 1; j <=i; j++)
            sum1 = min(cur_sum+triangle[i][j] , sum1);
        
    }
    return sum1 ;
}
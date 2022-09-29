// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
{
    if (matrix.empty()) 
        return 0;
    int rowlen = matrix.size();
    int collen = matrix[0].size();
    int ans1 = INT_MIN;
    for (int i1 = 0; i1 < collen; ++i1) 
    {
        vector<int> rowsum(rowlen, 0);
        for (int r1 = i1; r1 < collen; ++r1) 
        {
            for (int j1 = 0; j1 < rowlen; ++j1) 
                rowsum[j1] += matrix[j1][r1];
            
            int currentMax = INT_MIN;
            int currentsum = 0;
            set<int> subarrayset;
            subarrayset.insert(0);
            for (int sum : rowsum) 
            {
                currentsum += sum;
                set<int>::iterator it = subarrayset.lower_bound(currentsum - k);
                if (it != subarrayset.end()) 
                    currentMax = std::max(currentMax, currentsum - *it);
                subarrayset.insert(currentsum);
            }
            ans1 = std::max(ans1, currentMax);
        }
    }
    return ans1;
}






// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        vector<int>array_i(n*n);
        for(int i1 = 0 ;i1<n;i1++)
            for(int j1 = 0  ; j1<n ; j1++)
                array_i[i1*n+j1] = matrix[i1][j1];
        sort(array_i.begin(),array_i.end());
        return array_i[k-1];
    }   
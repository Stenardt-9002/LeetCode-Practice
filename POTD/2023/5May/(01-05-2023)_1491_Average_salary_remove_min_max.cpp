// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/








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






class Solution {
public:
    double average(vector<int>& salary) 
    {
        return (accumulate(begin(salary), end(salary), 0.) - *min_element(begin(salary), end(salary)) 
        - *max_element(begin(salary), end(salary))) / (salary.size() - 2);
    }
};
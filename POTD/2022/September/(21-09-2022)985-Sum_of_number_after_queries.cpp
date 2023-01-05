// https://leetcode.com/problems/sum-of-even-numbers-after-queries/https://leetcode.com/problems/sum-of-even-numbers-after-queries/https://leetcode.com/problems/sum-of-even-numbers-after-queries/https://leetcode.com/problems/sum-of-even-numbers-after-queries/



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

const long long int mod2 =  1e18 ;



vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
{

    int cur_sum = 0 ;
    for (auto i1: nums)
        if(i1%2==0)
        cur_sum+=i1 ;

    vector<int> ans1 ;

    for(auto vec : queries)
    {
        int val = vec[0];
        int index1 = vec[1];
        if(nums[index1]%2==0)
        {
            if(val%2==0)
                cur_sum+=val ;
            else 
                cur_sum-=nums[index1];
            
        }
        else 
        {
            if(val%2!=0)
                cur_sum+=(nums[index1]+val);
        }
        nums[index1]+=val ;

        ans1.push_back(cur_sum) ;
    }

    return ans1 ;


}




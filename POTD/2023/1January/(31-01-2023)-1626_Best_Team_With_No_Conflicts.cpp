

// https://leetcode.com/problems/best-team-with-no-conflicts/description/










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


class newData 
{
    public:
    int data , ages ;
    int sum1 ;
};

bool compare( newData a1 , newData b1)
{
    if(a1.ages==b1.ages)
        return a1.data<b1.data;
    return a1.ages<b1.ages ;
}

class Solution 
{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
                int n = scores.size();
        newData *arr = new newData[n];
        for (int i = 0; i < n; i++)
        {
            arr[i].data = scores[i];
            arr[i].ages = ages[i];
            arr[i].sum1 = scores[i];
        }
        sort(arr , arr+n , compare);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if(arr[i].data>=arr[j].data)
                    arr[i].sum1 = max(arr[i].sum1 , arr[j].sum1+arr[i].data);
            
        int ans = arr[0].sum1 ;
        for (int i = 1; i < n; i++)
            ans = max(ans , arr[i].sum1);
        return ans ;
    }
};
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// bool pick_non_pick_rec(int indx , int last_ele_squence_one , int length_seq1 ,int last_ele_squence_two ,int length_seq2,vector<int> nums )
// {
//     //put index in first sequence 
//     int orignanlsq1 = last_ele_squence_one ;
//     if(orignanlsq1==-1)
//         last_ele_squence_one = nums[indx];
//     else 
//     // length_seq1++ ;
//     if(pick_non_pick_rec(indx+1 , last_ele_squence_one ,length_seq1+1 , ))


// }

bool isPossible(vector<int>& nums) 
{
    unordered_map<int, int> left1, right1;
    for (int i: nums) 
        left1[i]++;

    for (int i: nums) 
    {
        
        if (left1[i] == 0) 
            continue;
        left1[i]--;
        
        if (right1[i - 1] > 0) 
        {   
                right1[i - 1]--;
                right1[i]++;
        }
        else if (left1[i + 1] > 0 && left1[i + 2] > 0) 
        {
                left1[i + 1]--;
                left1[i + 2]--;
                right1[i + 2]++;
        } 
        else 
            return false;
            
    }
    return true;
}
// bool isPossible(vector<int>& nums) 
// {

//     int n= nums.size();
//     int last_ele_squence_one=-1 ;
//     int length_seq1 = 0 ,length_seq2 = 0;
//     int last_ele_squence_two = -1 ;
//     if(pick_non_pick_rec(0 , last_ele_squence_one , length_seq1 ,last_ele_squence_two , length_seq2 ))
//         return true ;
//     return false ;


// }



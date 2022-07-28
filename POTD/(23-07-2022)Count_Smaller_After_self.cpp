// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

int MODE1 = 1000000007 ;

void mergeSort_util(vector<pair<int,int>>&containele_ind,int startind , int endind , vector<int>&answer)
{
    if(startind>=endind)
        return ; 
    
    int mid_idx = startind+(endind-startind)/2 ;
    mergeSort_util(containele_ind,startind,mid_idx,answer);
    mergeSort_util(containele_ind,mid_idx+1,endind,answer);


    int left_iterator = startind ;
    int right_iterator = mid_idx+1 ;
    int elementssmallerthanleft = 0;

    vector<pair<int,int>>merged_array ;

    while (left_iterator<=mid_idx && endind>=right_iterator)
    {
        if(containele_ind[left_iterator].first> containele_ind[right_iterator].first)//merge
        {
            elementssmallerthanleft++ ;
            merged_array.push_back(containele_ind[right_iterator]);
            right_iterator++ ;
        }
        else 
        {
            answer[containele_ind[left_iterator].second]+=elementssmallerthanleft;
            merged_array.push_back(containele_ind[left_iterator]);
            left_iterator++ ;
        }
    }
    //left side if elements remain
    while (left_iterator<=mid_idx )
    {
        answer[containele_ind[left_iterator].second]+=elementssmallerthanleft;
        merged_array.push_back(containele_ind[left_iterator]);
        left_iterator++ ;
    }

    while (endind>=right_iterator)
    {
        merged_array.push_back(containele_ind[right_iterator]);
        right_iterator++ ;
    }

    //copying values to original var
    int pos = startind ; 
    for( auto val_i: merged_array)
        containele_ind[pos++] = val_i;



}



vector<int> countSmaller(vector<int>& nums) 
{
    int n = nums.size();
    if(n==0)
        return {};

    vector<int> answer_1(n,0);
    vector<pair<int,int>> containele_ind(n);//
    for (int i1 = 0; i1 < n; i1++)
        containele_ind[i1] = {nums[i1],i1};
    

    mergeSort_util(containele_ind,0,n-1,answer_1);
    return answer_1 ;
}



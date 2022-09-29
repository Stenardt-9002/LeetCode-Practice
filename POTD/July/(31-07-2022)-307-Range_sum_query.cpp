// https://leetcode.com/problems/range-sum-query-mutable/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


class NumArray {
    
    
public:
    vector<int>nums_in ;
    vector<long long int>sum_val ;
    int n ;
    NumArray(vector<int>& nums) 
    {
        
        this->nums_in = nums ;
        this->n = this->nums_in.size();
        long long int sum1 = 0 ;
        for(int i1 = 0 ; i1<this->n ;i1++)
        {
            sum1+=nums[i1];
            this->sum_val.push_back(sum1);
        }
    
    }
    
    void update(int index, int val) 
    {
        this->nums_in[index] = val ;
        long long int sum_iter = 0;
        if(val>0)
            sum_iter = this->sum_val[val-1];
        
        for(int i1 = val ; i1<this->n ; i1++)
        {
            sum_iter+=(this->nums_in[i1]);
            this->sum_val[i1] = sum_iter ;
        }

    }
    
    int sumRange(int left, int right) 
    {
        int n = this->nums_in.size();
        int nas1 = this->sum_val[right];
        if(left>0)
            nas1 = this->sum_val[right]-this->sum_val[left-1] ;

        return nas1 ;
    }
};



class Our_class 
{ 
public:
    vector<int> var;
    Our_class(int size=0) 
    {
        var.assign(size + 1, 0);
    }
    int getSum(int index1) 
    { 
        int sum = 0;
        for (; index1 > 0; index1 -= index1 & (-index1))
            sum += var[index1];
        return sum;
    }
    void addValue(int index1, int val) {
        for (; index1 < var.size(); index1 += index1 & (-index1))
            var[index1] += val;
    }
};



class NumArray {
    
    
public:
    Our_class var;
    vector<int>nums_in ;


    NumArray(vector<int>& nums) 
    {
        this->var = Our_class(nums.size());
        this->nums_in = nums;
        for (int i = 0; i < nums.size(); ++i)
            var.addValue(i+1, nums[i]);
    }
    
    void update(int index, int val) 
    {
        int diff = val - nums_in[index]; 
        var.addValue(index + 1, diff);
        nums_in[index] = val;
    }
    
    int sumRange(int left, int right) 
    {
        return var.getSum(right+1) - var.getSum(left);
    }
};


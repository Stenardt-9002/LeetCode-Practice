// https://leetcode.com/problems/find-median-from-data-stream/









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




class MedianFinder {
public:
    multiset<double>smaller,larger ;
        
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        int ele ;
        if(smaller.empty()&&larger.empty() )
            larger.insert(num);
        else if (smaller.empty() || larger.empty() )
        {
            if((*(larger.begin()))>=num )
                smaller.insert(num);
            else 
            {
                ele = (*(larger.begin()));
                smaller.insert(ele);
                larger.erase(larger.begin());
                larger.insert(num);
            }
        }
        else if((*(--smaller.end()))<=num && num<=(*(larger.begin())) )
        {
            if(smaller.size()+1 == larger.size())
                smaller.insert(num);
            else 
                larger.insert(num);
        }   
        else if(*(--smaller.end())>=num )
        {
            if(smaller.size()==larger.size())
            {
                ele = (*(--smaller.end()));
                larger.insert(ele);
                smaller.erase(--smaller.end());
            }
            smaller.insert(num);
        }
        else 
        {
            if(smaller.size()+1==larger.size())
            {
                ele = (*(larger.begin()));
                smaller.insert(ele);
                larger.erase(larger.begin());
            }
            larger.insert(num);
        }
    }
    
    double findMedian() 
    {
        double ans1 = 0;
        if(smaller.size()==larger.size())
        {
            ans1 = *(--smaller.end())+*(larger.begin());
            ans1/=2 ;
        }
        else 
            ans1 = (*larger.begin());
        return ans1 ;
    }
};

int main()
{
    MedianFinder a1 ;
    a1.addNum(1);
    cout<<a1.findMedian()<<endl ;
    a1.addNum(2);
    cout<<a1.findMedian()<<endl ;
    a1.addNum(3);
    cout<<a1.findMedian()<<endl ;
}






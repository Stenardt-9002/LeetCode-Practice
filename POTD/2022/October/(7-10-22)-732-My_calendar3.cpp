// https://leetcode.com/problems/my-calendar-iii/




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





// class MyCalendarThree 
// {
//     public:
//     multiset<pair<int,int>> s1 ;
//     int max_collision ;
//     MyCalendarThree() 
//     {
//         this->max_collision = 1;
//     }
    
//     int book(int start, int end) 
//     {
//         int current_collision = 1;
//         bool break_loop = true ;
//         for (auto i = this->s1.begin(); i !=this->s1.end() && break_loop; i++)
//         {
//             if(i->first>=end)
//                 break_loop = false ;
//             else if( (i->first>start && i->first<end)||(i->second>start && i->second<end)||(start>i->first && start<i->second)||(end>i->first && end<i->second)||(i->first==start && i->second == end) )
//                 current_collision++ ;
//         }

//         this->s1.insert({start,end});
//         this->max_collision = max(this->max_collision , current_collision);
//         return this->max_collision ;
//     }
// };




class MyCalendarThree 
{
    public:
    map<int,int> m1 ;
    int max_collision ;
    MyCalendarThree() 
    {
        this->max_collision = 0;
    }
    
    int book(int start, int end) 
    {
        m1[start]++ ;
        m1[end]-- ;
        int current_collision = 0;
        for(auto c : m1)
        {
            current_collision+=(c.second) ;
            this->max_collision = max(this->max_collision , current_collision);
        }
        return this->max_collision ;
    }
};




// Please see and vote for my solutions for similar problems.
// 253. Meeting Rooms II
// 2406. Divide Intervals Into Minimum Number of Groups
// 2402. Meeting Rooms III
// 731. My Calendar II
// 732. My Calendar III
// 1094. Car Pooling
// 1109. Corporate Flight Bookings
// 218. The Skyline Problem


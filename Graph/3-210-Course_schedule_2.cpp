
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


void toposrt_util(vector<int> *adjacen_list,vector<int> &ans1,vector<bool>&visited,int cur_vertex , stack<int>& s1)
{
    visited[cur_vertex] = true ;
    for(auto neig:adjacen_list[cur_vertex])
        if(!visited[neig])
            toposrt_util(adjacen_list,ans1,visited,neig,s1);
    s1.push(cur_vertex);
}
bool iscycle_util(vector<int> *adjacen_list,int i1 ,vector<bool>&visited , vector<bool>&rec_stack )
{
    if(!visited[i1])
    {
        visited[i1] = true ;
        rec_stack[i1] = true ;

        for (auto neig:adjacen_list[i1])
        {
            if(!visited[neig]&&iscycle_util(adjacen_list,neig,visited,rec_stack))
                return true ;
            else if(rec_stack[neig])
                return true ;
        }
        


        rec_stack[i1] = false ;
    }
    return false ;
}
bool cycle_detection(vector<int> *adjacen_list , int numCourses)
{
    vector<bool>visited(numCourses , false);
    vector<bool>rec_stack(numCourses , false);
    for (int i1 = 0; i1 < numCourses; i1++)
        if(!visited[i1] && iscycle_util(adjacen_list,i1,visited,rec_stack) )    
            return true ;

    return false ;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<int> *adjacen_list = new vector<int>[numCourses];
    for(auto x : prerequisites)
        adjacen_list[x[1]].push_back(x[0]);


    if(cycle_detection(adjacen_list , numCourses))
        return {};


    vector<int> ans1 ;
    vector<bool>visited(numCourses,false);
    stack<int> s1 ;
    for (int i1 = 0; i1 < numCourses; i1++)
        if(!visited[i1])
            toposrt_util(adjacen_list,ans1,visited,i1,s1);


    while (!s1.empty())
    {
        ans1.push_back(s1.top())    ;
        s1.pop();
    }
    

    // toposrt_util(adjacen_list,ans1,visited,numCourses);
    delete[] adjacen_list ;
    return ans1 ;
}




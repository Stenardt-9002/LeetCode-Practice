// https://leetcode.com/problems/reconstruct-itinerary/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


// vector<string> findItinerary(vector<vector<string>>& tickets) 
// {
//     map<string,set<string>> graph1 ;//used for min
//     map<string,bool> edge_done ;
//     map<string,int>indgree;
//     map<string,int>oudgree;
//     map<string,int> node_list_val ;
//     int min1 = 99999 ;
//     for (auto xstr : tickets)
//     {
//         // if(graph1.find(xstr[0])==graph1.end())
//         graph1[xstr[0]].insert(xstr[1]);
//         string edge_var = xstr[0]+"->"+xstr[1];
//         edge_done[edge_var] = false ;
//         if(indgree.find(xstr[1])==indgree.end())
//             indgree[xstr[1]] = 1;
//         else 
//             indgree[xstr[1]]+=1;


//         if(oudgree.find(xstr[0])==oudgree.end())
//             oudgree[xstr[0]] = 1;
//         else 
//             oudgree[xstr[0]]+=1;


//         if(node_list_val.find(xstr[1])==node_list_val.end())
//             node_list_val[xstr[1]] = 2;
//         if(node_list_val.find(xstr[0])==node_list_val.end())
//             node_list_val[xstr[0]] = 2;
        

//     }


            

//     for (auto string1 : node_list_val)
//     {
//         if(indgree.find(string1.first)==indgree.end())
//             indgree[string1.first]=0;

//         if(oudgree.find(string1.first)==oudgree.end())
//             oudgree[string1.first]=0;
    
//     }



//     for ( auto nodes : node_list_val)
//         min1 = std::min({indgree[nodes.first],min1});

//     set<string> inti1 ;
//     queue<string> q1 ;
//     for(auto nodes1:indgree)
//         if(nodes1.second==min1)
//             inti1.insert(nodes1.first);
    
//     vector<string> final_ans1 ;




//     for (auto string1 : inti1)
//     {
//         q1.push(string1);
//         final_ans1.push_back(string1);
//         cout<<endl<<string1<<" "<<indgree[string1] ;
//     }
//     cout<<endl<<endl;
//     for (auto string1 : node_list_val)
//         cout<<string1.first<<" "<<indgree[string1.first]<<endl;

//     cout<<endl<<endl;
//     for (auto string1 : node_list_val)
//         cout<<string1.first<<" "<<oudgree[string1.first]<<endl;





//     while (!q1.empty())
//     {
//         string top_first = q1.front()     ;
//         q1.pop() ;
//         cout<<"\nDEBUG "<<top_first<<endl;
//         for (auto child:graph1[top_first])  
//         {
//             cout<<"\nDEBUG1 "<<child<<endl;

//             string cur_edge = top_first+"->"+child ;
//             if(!edge_done[cur_edge])
//             {
//                 edge_done[cur_edge]= true ;
//                 indgree[child]--;
//                 q1.push(child);
//                 if(indgree[child]==0)
//                     final_ans1.push_back(child);
//             }
//         }
//     }
//     return final_ans1;

    
// }

void dfs_util(string src ,map<string,multiset<string>>&graph1,vector<string>&final_ans1  ) 
{
    while (graph1[src].size())
    {
        string next = *graph1[src].begin();
        graph1[src].erase(graph1[src].begin());
        dfs_util(next,graph1,final_ans1);
    }
    final_ans1.push_back(src)    ;
}

vector<string> findItinerary(vector<vector<string>>& tickets) 
{
    map<string,multiset<string>> graph1 ;//used for min
    vector<string> final_ans1 ;

    for(auto stations:tickets)
        graph1[stations[0]].insert(stations[1]);

    dfs_util("JFK",graph1,final_ans1);
    reverse(final_ans1.begin(),final_ans1.end());
    return final_ans1;
}


int main(int argc, char const *argv[])
{
    vector<vector<string>> input1 ; 
    int V ;
    cin>>V ;
    vector<string> temp1(2);
    for (int i1 = 0;i1<V;i1++)
    {
        cin>>temp1[0]>>temp1[1];
        input1.push_back(temp1);
    }
    //   for (auto ans1 : input1)
    //     cout<<ans1[0]<<" "<<ans1[1]<<endl    ;

    vector<string>returnans = findItinerary(input1);
    cout<<endl;
    for (auto ans1 : returnans)
        cout<<ans1<<" "    ;
    
    cout<<endl;
    return 0;
}


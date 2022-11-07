// https://leetcode.com/problems/minimum-genetic-mutation/







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


bool ischild(string parent , string child)
{
    if(child=="-1")
        return false;
    int no_of_changes = 0 ;
    for(int i1 =0;i1<8;++i1)
        no_of_changes+=(!(parent[i1]==child[i1]));

    return no_of_changes==1 ;
}

void DEUG(queue<string> q1)
{
    cout<<endl ;
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    
}

int minMutation(string start, string end, vector<string>& bank) 
{
    int ans1 = 0 ;
    if(start==end)
        return 0;
    queue<string> q1 ;
    q1.push(start);
    while (!q1.empty())
    {
        int n = q1.size();
        ans1++;
        while (n--)
        {
            string curr = q1.front()   ;
            q1.pop();
            if(curr==end)
                return ans1-1;

            for (auto &str:bank)
                if(ischild(curr,str))
                {
                    q1.push(str);
                    str = "-1";
                }
        }
    }
    return -1 ;
}



int minMutation(string start, string end, vector<string>& bank) 
{
    set<string> banks_1 ;
    for (auto str1 : bank)
        banks_1.insert(str1);

    int ans1 = 0 ;
    if(banks_1.find(end)==banks_1.end())
        return -1 ;

    string src = start ;
    int i1 ;
    // current queue 
    queue<string> q1 ;
    q1.push(src);
    while (!q1.empty())
    {
        for (i1 = 0; i1 < q1.size(); i1++)
        {
            string curr = q1.front()            ;
            q1.pop();
            if(curr==end)
                return ans1;
            vector<string> to_delete;
            for(auto childnode:banks_1)
                if(ischild(curr , childnode))
                {
                    to_delete.push_back(childnode);
                    q1.push(childnode);
                }
            
            for(auto x : to_delete)
                banks_1.erase(banks_1.find(x));
        }
        ans1++;
    }
    return -1 ;
}





int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        string start,end ;
        cin>>start>>end;

        int n ;
        cin>>n;
        vector<string> bank(n) ;
        for(auto &x:bank)
            cin>>x ;
        cout<<minMutation(start, end, bank) ;
        cout<<endl;
    }
    

    return 0;
}













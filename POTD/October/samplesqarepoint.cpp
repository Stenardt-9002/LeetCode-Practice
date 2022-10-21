


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






// vector<pair<string,int>> solve(vector<string>string_list)
// {
//     // unordered_map<string , int>hash_map ;
//     vector<pair<string,int>> ans1 ;
//     unordered_map<string , vector<int>>hash_map ;

//     int n = string_list.size();
//     for(int i1 = 0 ;i1<n ; i1++)
//     {
//         string c = string_list[i1];
//         sort(c.begin(),c.end());
//         hash_map[c].push_back(i1) ;
//     }





//     auto cmp = [](pair<string,int> a, pair<string,int> b) { return a.second>b.second ;};    
//     multiset<pair<string,int>,decltype(cmp)> heap1(cmp) ;

//     for (auto pair1 : hash_map)
//         heap1.insert({pair1.first,pair1.second.size()});








//     while(heap1.size()!=0)
//     {
//         pair<string,int> output = *(heap1.begin());
//         heap1.erase(heap1.begin());
//         int current_size = output.second ;
//         set<int> indexes(hash_map[output.first].begin() ,hash_map[output.first].end()) ;
//         //to print 
//         while(heap1.size()!=0 && heap1.begin()->second == current_size)
//         {
//             //ordering of string
//             pair<string,int> output2 = *(heap1.begin());
//             heap1.erase(heap1.begin());
//             for(auto index : hash_map[output2.first])
//                 indexes.insert(index);

//         }
//         for(auto indexpos : indexes)
//             ans1.push_back({string_list[indexpos] , current_size}); 
//     }

//     return ans1 ;
// }


vector<string> func(string line)
{
    vector<string> ans1 ;
    string temp1 = "";
    for(auto c : line)
    {
        if(isalnum(c))
            temp1+=c ;
        else if(temp1.size()>0)
        {
            ans1.push_back(temp1);
            temp1 = "";
        }
    }
    if(temp1!="")
        ans1.push_back(temp1);

    return ans1 ;
}

int pos(char a)
{

    if(a>='A'&& a<='Z')
        return a-'A'+26;
    else if(a>='0'&& a<='9')
        return a-'0'+52 ;
    return a-'a';
}
vector<pair<string,int>> solve(vector<string>string_list)
{
    vector<pair<vector<int>,int>> ans1 ;
    unordered_map<vector<int> , vector<int>>hash_map ;

    int n = string_list.size();
    for(int i1 = 0 ;i1<n ; i1++)
    {
        vector<int>char_map(62,0);
        for(auto ch:string_list[i1])
            char_map[pos(ch)]++ ;
        hash_map[char_map].push_back(i1) ;
    }





    auto cmp = [](pair<vector<int>,int> a, pair<vector<int>,int> b) { return a.second>b.second ;};    
    multiset<pair<string,int>,decltype(cmp)> heap1(cmp) ;

    for (auto pair1 : hash_map)
        heap1.insert({pair1.first,pair1.second.size()});








    while(heap1.size()!=0)
    {
        pair<string,int> output = *(heap1.begin());
        heap1.erase(heap1.begin());
        int current_size = output.second ;
        set<int> indexes(hash_map[output.first].begin() ,hash_map[output.first].end()) ;
        //to print 
        while(heap1.size()!=0 && heap1.begin()->second == current_size)
        {
            //ordering of string
            pair<string,int> output2 = *(heap1.begin());
            heap1.erase(heap1.begin());
            for(auto index : hash_map[output2.first])
                indexes.insert(index);

        }
        for(auto indexpos : indexes)
            ans1.push_back({string_list[indexpos] , current_size}); 
    }

    return ans1 ;
}




/*
    bool comparator(string a , string b)
    {
        return hash_count[word2hash[a]]>hash_count[word2hash[b]];
    }


    map<map<char,int> , int >hash_count;
    map<string,map<char,int>>word2hash;

    vector<string> input ;
    stable_sort(input.begin(),input.end(),comparator);
*/

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
        // vector<string>string_list = {"foo", "ofo","oof","bar","cat","abr","tac","abc","atack","aactk","caatk","ktaac","office"};
        vector<string>string_list = {"foo", "bar","ofo","abr","oof"};

        vector<pair<string,int>>ans1 = solve(string_list);
        for(auto x: ans1)
            cout<<x.first<<" "<<x.second<<"," ;
    }


    return 0;
}


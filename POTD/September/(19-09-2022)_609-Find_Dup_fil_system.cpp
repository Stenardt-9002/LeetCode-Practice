// https://leetcode.com/problems/find-duplicate-file-in-system/




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


void DEUG_fuc(vector<string> pro)
{
    cout<<"\nDEBUG1 ";
    for (auto x: pro)
        cout<<"  KOXK"<<x<<"J" ;
    cout<<"\nDEBUG2\n";
    
}
void DEUG_fuc2(string a , string b )
{
    cout<<"\nDEBUG?"<<a<<" "<<b<<"!";
    cout<<"\nDEBUG2\n";
}



vector<vector<string>> findDuplicate(vector<string>& paths) 
{
    unordered_map<string ,vector<string>>hash_1 ;
    vector<vector<string>> ans1 ;
    for(auto processstring : paths)
    {
        int startindex =0 ;
        int size_str = processstring.size();
        vector<string> processed ;
        for (int i1 = 0; i1 < size_str; i1++)
            if(processstring[i1]==' ')
            {
                processed.push_back(processstring.substr(startindex , i1-startindex ));
                startindex = i1+1 ;
            }
        processed.push_back(processstring.substr(startindex));



        // DEUG_fuc(processed);
        int vecsize = processed.size();
        string path_file = processed[0];
        path_file+="/";
        for (int i1 = 1; i1 < vecsize; i1++)
        {
            string filecontent = processed[i1];
            //get file name and content 

            int sizefile = filecontent.length();
            int indexoffirstbrack = -1 ;
            for (int j1 = 0; j1 < sizefile && indexoffirstbrack==-1; j1++)
                if(filecontent[j1]=='(')
                   indexoffirstbrack = j1 ;

            string filename = filecontent.substr(0 , indexoffirstbrack);
            string filetext = filecontent.substr(indexoffirstbrack+1 ,filecontent.length()-1-(indexoffirstbrack+1) );
            hash_1[filetext].push_back(path_file+filename);
            // DEUG_fuc2(filetext , path_file+filename);
        }
        
        
    }

    for(auto x : hash_1)
    {
        if(x.second.size()>=2)
        ans1.push_back(x.second);

        // cout<<"\nED"<<x.first;
        // cout<<"\n All strings ";
        // for(auto s1tring : x.second)
        //     cout<<" "<<s1tring;
        
        ans1.push_back(x.second);
    }
    
    return ans1 ;

}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ;//, target;
    testcase=1 ;
    // cin>>testcase;
    while (testcase--)
    {
        vector<string> input1 ;
        input1.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
        input1.push_back("root/c 3.txt(abcd)");
        input1.push_back("root/c/d 4.txt(efgh)");
        input1.push_back("root 4.txt(efgh)");
        vector<vector<string>> output = findDuplicate(input1);
        for(auto vec : output)
        {
            for(auto str1 : vec)
                cout<<" "<<str1 ;
            cout<<endl; 
        }
    }
    return 0 ;
}

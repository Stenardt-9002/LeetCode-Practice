#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// tuple <char, int, float> geek ;
// get<0>(geek)


// pair<int, char> PAIR1;
// PAIR1.first ;
void print_tack(stack<int> a)
{
    cout<<endl<<endl ;
    while (a.empty()==false)
    {
        cout<<a.top()<<endl ;
        a.pop() ;
    }
    cout<<endl<<endl ;
}


// https://www.delftstack.com/howto/cpp/cpp-split-string-by-space/#:~:text=in%20C%2B%2B.-,Use%20std%3A%3Astring%3A%3Afind%20and%20std%3A%3Astring,value%20or%20a%20single%20character.
void processLine_cpp()
{
     string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                  "Sed laoreet sem leo, in posuere orci elementum.";
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    words.push_back(text);

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
        
    }
    

    return 0;
}






// https://leetcode.com/problems/reverse-vowels-of-a-string/







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











bool isvowel(char a)
{
    return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U');
}

class Solution {
public:
    string reverseVowels(string s) 
    {
        int n = s.size();
        int ptr1 = 0    ,ptr2 = n-1;
        while(ptr1<ptr2)
        {
            while(ptr1<n && !isvowel(s[ptr1]))
                ptr1++ ;
            while( ptr2>=0 && !isvowel(s[ptr2]))
                ptr2-- ;
            if(ptr1<ptr2)
                swap(s[ptr1],s[ptr2]);
            ptr1++ ;
            ptr2--;
        }
        return s ;
    }
};
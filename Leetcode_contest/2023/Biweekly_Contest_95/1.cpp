


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
                bool bulky = false ;
        bool heavy = false ;
        long long volume = (long long)length*(long long)width*(long long)height;
        if (max({length,height,width})>=10000 || volume>=1000000000)    
            bulky = true ;
        if(mass>=100)
            heavy = true ;
        if(heavy&&bulky)
            return "Both";
        else if(heavy||bulky)
        {
            if(heavy)
            return "Heavy";
            if(bulky)
            return "Bulky";
        }
        return "Neither";
    }
};


int main(int argc, char const *argv[])
{

    // vector<int > nums1 = {50,20,50,40,20};
    // vector<int > nums2 = {20,40,20,70,30};

    vector<int > nums1 = {10,20,50,15,30,10};
    vector<int > nums2 = {40,20,10,100,10,10};
    return 0;
}







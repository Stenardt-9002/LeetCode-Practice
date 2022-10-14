// https://leetcode.com/contest/weekly-contest-313/problems/minimize-xor/

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


int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x-1);
        count++;
    }
    return count;
}


class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        
        int bitsinone = countSetBits(num1);
        int bitsintrow = countSetBits(num2);

        int orig1 = num1 ;
        if(bitsinone==bitsintrow)
        {
            return num1;
        }
        else if(bitsinone>bitsintrow)
        {
            int ans1_bits = bitsinone-bitsintrow ;
            int ans1 = 0;
            int power = 0;
            while(ans1_bits!=0)
            {
                if(num1%2==1)
                {
                    ans1_bits--;
                    ans1 += pow(2,power);
                }
                num1/=2 ;
                power+=1 ;
            }
            return ans1^orig1 ;
        }
        else 
        {
            int ans1_bits = bitsintrow-bitsinone ;
            int ans1 = 0;
            int power = 0;
            while(ans1_bits!=0)
            {
                if(num1%2==0)
                {
                    ans1_bits--;
                    ans1 += pow(2,power);
                }
                num1/=2 ;
                power+=1 ;
            }
            return ans1^orig1 ;
        }
    }
};


int main(int argc, char const *argv[])
{
    int num1 , num2 ;
    cin>>num1>>num2 ;
    int a = __builtin_popcount(num1), b = __builtin_popcount(num2);

    cout<<endl<<a<<" "<<b ;
    
    
    return 0;
}




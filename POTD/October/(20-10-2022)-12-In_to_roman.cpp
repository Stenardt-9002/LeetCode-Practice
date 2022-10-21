// https://leetcode.com/problems/integer-to-roman/




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



string convertstring_symbol(int val)
{
    string ans1 = "";
    if(val>=1&&val<4)
    {
        ans1 = "I";
        for(int i1=1;i1<val;i1++)
            ans1+="I";
    }
    else if(val==4)
        return "IV";

    else if(val>=5&&val<=8)
    {
        ans1 = "V";
        for(int i1=0;i1<val-5;i1++)
            ans1+="I";
    }
    else if(val==9)
        return "IX";




    else if(val>=10 && val<=30)
    {
        ans1 = "X";
        for(int i1=0;i1<val-10;i1+=10)
            ans1+="X";
    }
    else if(val==40)
    {
        return "XL";
    }
    else if(val>=50 && val<=80)
    {
        ans1 = "L";
        for(int i1=50;i1<val;i1+=10)
            ans1+="X";
    }
    else if(val==90)
    {
        return "XC";
    }



    else if(val>=100 && val<=300)
    {
        ans1 = "C";
        for(int i1=100;i1<val;i1+=100)
            ans1+="C";
    }
    else if(val==400)
    {
        return "CD";
    }
    else if(val>=500 && val<=800)
    {
        ans1 = "D";
        for(int i1=500;i1<val;i1+=100)
            ans1+="C";
    }
    else if(val==900)
    {
        return "CM";
    }
    else if(val>=1000 && val<=3000)
    {
        ans1 = "M";
        for(int i1=1000;i1<val;i1+=1000)
            ans1+="M";
    }

    return ans1 ;
}


string intToRoman(int num) 
{
    string ans1 = "";
    int digits = floor(log10(num))+1;
    int power = 10 ;
    while(digits--)    
    {
        ans1 = convertstring_symbol(num%power)+ans1;
        num = num-(num%power);
        power*=10 ;
    }
    return ans1 ;
}


int main()
{
    cout<<intToRoman(3)<<endl;
    cout<<intToRoman(58)<<endl;
    cout<<intToRoman(1994)<<endl;
    cout<<intToRoman(60)<<endl;



}
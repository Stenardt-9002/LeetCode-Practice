// https://leetcode.com/problems/image-overlap/




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


int cmmon_overlap(vector<vector<int>> img1, vector<vector<int>> img2 ,int xshift , int yshift ,int n)
{
    int count1_sum = 0;

}
//O(n^4)
int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
{
    int n = img1.size()    ;
    //count ones 
    int count1 = 0,count2 =0;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            count1+=img1[i1][j1];


    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            count2+=img2[i1][j1];

    if(count2>count1)
        return largestOverlap(img2,img1);

    for (int xshift = 0; xshift < n; xshift++)
    {
        for (int yshift = 0; yshift < n; yshift++)
        {
            
        }
        
    }
    


}


//excellent method which made me shout
//most optimsed
int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
{
        int extra = 37 ;
        vector<int> imgvec1, img2vec;
        int N = img1.size(), ans1 = 0;
        // map<int, int> count;
        vector<int> count(2500,0);
        for (int i = 0; i < N * N; ++i)
        {
            if (img1[i / N][i % N] )
                imgvec1.push_back(i / N * extra + i % N);

        // for (int i = 0; i < N * N; ++i)
            if (img2[i / N][i % N] )
                img2vec.push_back(i / N * extra + i % N);
        }
        for (int i : imgvec1) 
            for (int j : img2vec) 
                count[i - j+1250]++;
        
        for(int i1 = 0 ; i1<2500;i1++)
            ans1 = max(ans1, count[i1]);

        return ans1;
}












    //excellent method which made me shout
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
            int extra = 61 ;
            vector<int> imgvec1, img2vec;
            int N = img1.size(), ans1 = 0;
            // map<int, int> count;
            vector<int> count(100000,0);
            for (int i = 0; i < N * N; ++i)
            {
                if (img1[i / N][i % N] )
                    imgvec1.push_back(i / N * extra + i % N);

            // for (int i = 0; i < N * N; ++i)
                if (img2[i / N][i % N] )
                    img2vec.push_back(i / N * extra + i % N);
            }
            for (int i : imgvec1) 
                for (int j : img2vec) 
                    count[i - j+50000]++;
            
            for(int i1 = 0 ; i1<100000;i1++)
                ans1 = max(ans1, count[i1]);
            // for (auto it : count) 
            //     ans1 = max(ans1, it.second);
            return ans1;
    }

//excellent method which made me shout
int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
{
        int extra = 61 ;
        vector<int> imgvec1, img2vec;
        int N = img1.size(), ans1 = 0;
        // map<int, int> count;
        vector<int> count(100000,0);
        for (int i = 0; i < N * N; ++i)
        {
            if (img1[i / N][i % N] )
                imgvec1.push_back(i / N * extra + i % N);

        // for (int i = 0; i < N * N; ++i)
            if (img2[i / N][i % N] )
                img2vec.push_back(i / N * extra + i % N);
        }
        for (int i : imgvec1) 
            for (int j : img2vec) 
                count[i - j+50000]++;
        
        for(int i1 = 0 ; i1<100000;i1++)
            ans1 = max(ans1, count[i1]);
        // for (auto it : count) 
        //     ans1 = max(ans1, it.second);
        return ans1;
}





    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

            vector<int> imgvec1, img2vec;
            int N = img1.size();
            unordered_map<int, int> count;
            for (int i = 0; i < N * N; ++i)
                if (img1[i / N][i % N] == 1)
                    imgvec1.push_back(i / N * 100 + i % N);

            for (int i = 0; i < N * N; ++i)
                if (img2[i / N][i % N] == 1)
                    img2vec.push_back(i / N * 100 + i % N);

            for (int i : imgvec1) 
                for (int j : img2vec) 
                    count[i - j]++;
            int res = 0;
            for (auto it : count) 
                res = max(res, it.second);
            return res;
    }


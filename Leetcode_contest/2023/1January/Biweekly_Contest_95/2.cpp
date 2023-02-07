





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;





class DataStream {
public:
            int pos = 0 ;
        int size ;
        unordered_map<int,int> map1;
        vector<int>vec ;
        int value ;
        int unique_ele = 0 ;
        int times = 0;
    DataStream(int value, int k) 
    {
        pos = 0 ;
        size = k;
        vec.resize(k) ;
        this->value = value;
        unique_ele = 0 ;
    }
    
    bool consec(int num) 
    {
        if(this->pos>=this->size)
        {
            //delete 
            if(--this->map1[this->vec[(this->pos)%this->size]]==0)
                unique_ele--;
        }
        this->vec[(this->pos++)%(this->size)] = num ;
        if(++this->map1[num]==1)
            this->unique_ele++;

        if(this->pos<this->size)
            return false ;
        
        // cout<<this->unique_ele<<" "<<this->vec[0]<<" "<<this->value<<endl;
        if(this->unique_ele==1 && this->vec[0]==this->value)
            return true ;
            
        return false ;

    }
//     DataStream(int value, int k) {
        
//     }
    
//     bool consec(int num) {
        
//     }
};
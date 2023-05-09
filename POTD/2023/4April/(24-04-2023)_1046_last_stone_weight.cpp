class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        if(stones.size()<2)
            return stones.size()==0?0:stones[0];
        
        multiset<int> s1(stones.begin(),stones.end()) ; 
        while(s1.size()>1)
        {
            int ym = *(--s1.end()) ; 
            s1.erase(--s1.end());
            int lsm =*(--s1.end()) ; 
            s1.erase(--s1.end());
            if(ym!=lsm)
                s1.insert(ym-lsm);
        }
        return s1.size()==0?0:*(s1.begin());

    }
};
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {

public:
    string removeDuplicates(string s) {
            stack<char> s1 ;
        for(auto c : s)
            if(!s1.empty()&& s1.top()==c)
                s1.pop();
            else 
                s1.push(c);

        s = "";
        while (!s1.empty())
        {
            s+=s1.top()    ;
            s1.pop();
        }
        reverse(s.begin(),s.end());
        return s ;
    }
};
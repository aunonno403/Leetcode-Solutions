#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char>st;
        for(auto i:s)
        {
            if(i=='('||i=='{'||i=='[') st.push_back(i);
           else {
                if (st.empty()) return false; 

                if (i == ')' && st.back() == '(') st.pop_back();
                else if (i == '}' && st.back() == '{') st.pop_back();
                else if (i == ']' && st.back() == '[') st.pop_back();
                else return false;
            }
        }
        return st.empty();        
    }
};
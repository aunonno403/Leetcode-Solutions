#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
    vector<char> st;
    unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
    for (char c:s){
        if(vowels.count(c))
        {
            st.push_back(c);
        }
    }
     
    for (int i = 0; i < s.length(); i++) {
        if (vowels.count(s[i])) {
            s[i] = st.back();
            st.pop_back();
        }
    }
    return s;        
    }
};
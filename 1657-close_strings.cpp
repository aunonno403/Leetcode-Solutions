#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int>w1,w2;
        for(int i=0;i<word1.size();i++)
        {
            w1[word1[i]]++;
            w2[word2[i]]++;
        }
        if(w1.size()!=w2.size()) return false;

        vector<int>frq1,frq2;
        for(auto& [ch, count] : w1) 
        {
            if(!w2.count(ch))return false;
            frq1.push_back(count);
        }
        for(auto& [ch, count] : w2)
        {
           frq2.push_back(count);
        }
        sort(frq1.begin(),frq1.end());
        sort(frq2.begin(),frq2.end());
        return frq1==frq2;
    }
};
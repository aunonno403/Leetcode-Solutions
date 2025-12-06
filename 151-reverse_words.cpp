#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> w;
        string temp="";
        string res;
        for(char c:s)
        {
            if(c==' ')
            {
                if(!temp.empty())
                {
                    w.push_back(temp);
                    temp="";
                }
            }
            else temp+=c;
        }
        if(!temp.empty()) w.push_back(temp);
        for(int i=w.size()-1;i>=0;i--)
        {
            res+=w[i];
            if(i!=0) res+=" ";
        }
        return res; 
        
    }
};
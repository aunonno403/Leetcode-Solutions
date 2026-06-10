#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>=s.length()) return s;
        vector<vector<char>>fq(numRows);
        int idx=0,d=1;
        for(auto ch:s)
        {
            fq[idx].push_back(ch);
            if(idx>=numRows-1){
                d=-1;
            }
            else if (idx==0)
            {
                d=1;
            }
            
            idx+=d;
        }
        string ans;
        for(auto i:fq)
            for(auto j:i)
            {
                ans.push_back(j);
            }
        return ans;
    }
};
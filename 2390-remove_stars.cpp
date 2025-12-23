#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto it:s)
        {
            if(it=='*') {
                if(!ans.empty()) {  
                    ans.pop_back();
                }
            }
            else ans.push_back(it);
        }        
        return ans;
    }
};
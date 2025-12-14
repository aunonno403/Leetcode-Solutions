#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>ans,temp;
        temp.push_back(chars[0]);
        for(int i=1;i<chars.size();i++) 
        {
            if(chars[i]==temp.back())
            {
                temp.push_back(chars[i]);
            }
            else{
                int n=temp.size();
                ans.push_back(temp.back());
                if(n > 1) {  
                    string s=to_string(n);
                    ans.insert(ans.end(),s.begin(),s.end());
                }
                temp.clear();
                temp.push_back(chars[i]);
            }
        }
        int n=temp.size();
        ans.push_back(temp.back());
        if(n > 1) {  
            string s=to_string(n);
            ans.insert(ans.end(),s.begin(),s.end());
        }
        chars.clear();
        chars=ans;
        return chars.size();
             
    }
};
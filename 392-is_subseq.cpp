#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int i=0;
        if(i==n) return true;
        for(auto it:t)
        {
            
            if(it==s[i])
            {
                i++;
                if(i==n) return true;                
            }
            
        }
        return false;
    }
};
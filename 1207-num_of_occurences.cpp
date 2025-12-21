#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(auto& it:arr) freq[it]++;
        unordered_map<int,vector<int>>dup;
        for(auto [num,cnt]:freq)
        {
            dup[cnt].push_back(num);
        }
        for(auto it:dup)
        {
            if(it.second.size()>1) return false;
        }
        return true;
        
    }
};
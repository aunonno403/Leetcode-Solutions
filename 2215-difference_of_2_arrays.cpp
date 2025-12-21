#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        unordered_set<int>s1,s2;
        for(int& it:nums1)
        {
            s1.insert(it);
        }
        for(int& it:nums2)
        {
            s2.insert(it);
        }
        for(int& it:nums1)
        {
            if(!s2.count(it)){
                ans[0].push_back(it);
                s2.insert(it);}
        }
        for(int& it:nums2)
        {
            if(!s1.count(it)){ans[1].push_back(it);s1.insert(it);}
        }
        return ans;
        

    }
};
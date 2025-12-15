#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> frq;
        int pairs=0;
        for(auto x:nums)
        {
            if(x<k){
                int c=k-x;
                auto it=frq.find(c);
                if(it!=frq.end()&&it->second>0)
                {
                    --(it->second);
                    ++pairs;
                } 
                else ++frq[x];
            }
            
        }
        return pairs;
    }
};
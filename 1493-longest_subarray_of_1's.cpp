#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen=0,len=0;
        int i=0,zeros=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0)zeros++;
            while(zeros>1)
            {
                if(nums[i]==0)zeros--;
                i++;
            }
            len=j-i+1;
            if(len>maxLen)
            {
                maxLen=len;

            }
        }
        return maxLen-1;
        
        
    }
};
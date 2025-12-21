#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return 0;
        vector<int>prefixsum(n),sufixsum(n);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        sufixsum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sufixsum[i]=sufixsum[i+1]+nums[i];
        }
        if(sufixsum[1]==0)return 0;
        for(int i=1;i<n-1;i++)
        {
            if(prefixsum[i-1]==sufixsum[i+1])return i;
        }        
        if(prefixsum[n-2]==0)return n-1;
        return -1;
    }
};
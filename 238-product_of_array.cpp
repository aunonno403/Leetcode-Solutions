#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> sufixsum(n);
        vector<int> prefixsum(n);
        vector<int> res(n);
        prefixsum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i-1] * nums[i];
        }
        sufixsum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sufixsum[i]=sufixsum[i+1]*nums[i];
        }
        for(int i=1;i<n-1;i++)
        {
            res[i]=(prefixsum[i-1]*sufixsum[i+1]);
        }
        res[0]=sufixsum[1];
        res[n-1]=prefixsum[n-2];
        return res;
    }
};
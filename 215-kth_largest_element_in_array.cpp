#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int p=partition(nums,l,r);
            if(p==k-1) return nums[p];
            if(p>k-1) r=p-1;
            else l=p+1;
        }
        return -1;
    }
    int partition(vector<int>& nums, int l,int r)
    {
        int i=l;
        int pivot=nums[r];
        for(int j=l;j<r;++j)
        {
            if(nums[j]>pivot)
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
};
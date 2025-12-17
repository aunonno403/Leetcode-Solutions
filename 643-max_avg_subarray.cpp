#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=accumulate(nums.begin(),nums.begin()+k,0.0),avg=sum/k;
        double max_avg=avg;
        if(nums.size()==k) return max_avg;
        int i=0,j=k;
        while(j<nums.size())
        {
            sum=sum+nums[j]-nums[i];
            avg=sum/k;
            if(avg>max_avg) max_avg=avg;
            i++;
            j++;
        }
        return max_avg;
    }
};
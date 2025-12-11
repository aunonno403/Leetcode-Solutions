#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n=nums.size();
//         int first=INT_MAX,second=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]<=first)
//             {
//                 first=nums[i];
//             }
//             else if(nums[i]<=second)
//             {
//                 second=nums[i];
//             }
//             else return true;

//         }
//         return false;
//     }
// };
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        vector<int>prefix(n),sufix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<prefix[i-1])prefix[i]=nums[i];
            else prefix[i]=prefix[i-1];
        }
        sufix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>sufix[i+1])sufix[i]=nums[i];
            else sufix[i]=sufix[i+1];
        }
        for(int i=1;i<n-1;i++)
        {
            if(prefix[i-1]<nums[i]&&nums[i]<sufix[i+1]) return true;
        }
        return false;
    }
};
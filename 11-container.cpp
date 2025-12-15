#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int max_h20=0;
        while(i<j)
        {
           int area=min(height[i],height[j])*(j-i);
           if(area>max_h20)
           {
            max_h20=area;
           }
           if(height[i]>=height[j]) j--;
           else i++;
        }
        return max_h20;
    }
};
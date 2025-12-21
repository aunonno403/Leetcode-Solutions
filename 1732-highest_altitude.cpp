#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,max=0;
        for(auto& it:gain)
        {
            sum+=it;
            if(sum>=max)max=sum;
        }
        return max;
        
    }
};
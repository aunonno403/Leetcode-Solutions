#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        
        for(int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long maxScore = 0;
        
        for(auto& [min_val, num1_val] : pairs) {
            minHeap.push(num1_val);
            sum += num1_val;
            
            if(minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            if(minHeap.size() == k) {
                maxScore = max(maxScore, sum * (long long)min_val);
            }
        }
        
        return maxScore;
    }
};
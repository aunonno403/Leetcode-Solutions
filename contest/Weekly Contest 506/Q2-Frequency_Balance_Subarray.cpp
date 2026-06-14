#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            map<int,int> fq;
            int max_fq=0;
            int dist_elm=0;
            map<int,int> fq_cnt;
            
            for(int j=i;j<nums.size();j++)
            {
                if(fq[nums[j]] == 0) dist_elm++;

                fq_cnt[fq[nums[j]]]--;   
                fq[nums[j]]++;            
                fq_cnt[fq[nums[j]]]++;   
                max_fq = max(max_fq, fq[nums[j]]);  

                if(dist_elm == 1){
                    ans = max(ans, j-i+1);
                }
                else if(max_fq % 2 == 0
                    && fq_cnt[max_fq/2] >= 1
                    && fq_cnt[max_fq] + fq_cnt[max_fq/2] == dist_elm){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
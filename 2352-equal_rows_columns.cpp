#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>rws;
        for(auto& it:grid)
        {
            rws[it]++;
        }
        for(int i=0;i<grid.size();i++)
            for(int j=i+1;j<grid[i].size();j++)
            {
                swap(grid[i][j],grid[j][i]);
            }
        int cnt=0;
        for(auto& it:grid)
        {
            if(rws.count(it)) cnt+=rws[it];
        }
        return cnt;
        
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<vector<int>>q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int l=q.size();
            bool rotted = false;
            for(int i=0;i<l;i++)
            {
                vector<int> nd=q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x=nd[0]+dirs[k][0];
                    int y=nd[1]+dirs[k][1];
                    if(x<0||y<0||x>=m||y>=n||grid[x][y]==0||grid[x][y]==2) continue;
                    if(grid[x][y]==1)
                    {
                        q.push({x,y});
                        grid[x][y]=2;
                        rotted = true;
                    }
                }
            }
            if(rotted) ans++;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;


    }
};
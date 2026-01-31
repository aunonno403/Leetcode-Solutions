#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans=0;
        queue<vector<int>>q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]]='+';
        vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        int rws=maze.size();
        int cols=maze[0].size();
        while(!q.empty())
        {
            int l=q.size();
            for(int k=0;k<l;k++)
            {
                vector<int>n=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=n[0]+dirs[i][0];
                    int y=n[1]+dirs[i][1];
                    if(x<0||y<0||x>=rws||y>=cols||maze[x][y]=='+') continue;
                    if(x==0||y==0||x==rws-1||y==cols-1) return ans+1;
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
            ans++;
        }
        return -1;

        
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> idx_map;
        int idx=0;
        for(auto &x:equations)
        {
            if(!idx_map.count(x[0])) idx_map[x[0]]=idx++;
            if(!idx_map.count(x[1])) idx_map[x[1]]=idx++;
        }
        int N=idx_map.size();
        vector<vector<int>> graph(N);
        for(auto &x:equations)
        {
            int u=idx_map[x[0]];
            int v=idx_map[x[1]];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int n=equations.size();
        unordered_map<string,double> W;
        for(int i=0;i<n;i++)
        {
            int u=idx_map[equations[i][0]];
            int v=idx_map[equations[i][1]];
            W[to_string(u)+","+to_string(v)]=values[i];
            W[to_string(v)+","+to_string(u)]=1.0/values[i];
        }
        vector<double>ans;
        for(auto &q:queries)
        {
            if(!idx_map.count(q[0])||!idx_map.count(q[1]))
            {
                ans.push_back(-1.0);
                continue;
            }
            int st=idx_map[q[0]];
            int ed=idx_map[q[1]];
            vector<bool>vis(N,0);
            vis[st]=true;
            double res=dfs(st,ed,graph,1.0,vis,W);
            res==0.0? ans.push_back(-1.0):ans.push_back(res);
        }
        return ans;

    }

    double dfs(int st,int ed, vector<vector<int>> &graph,double curr,vector<bool>&vis,unordered_map<string,double>&W)
    {
        if(st==ed) return curr;
        double r=0.0;
        for(auto &nei:graph[st])
        {
            if(!vis[nei])
            {
                vis[nei]=true;
                string key=to_string(st)+","+to_string(nei);
                r+=dfs(nei,ed,graph,curr*W[key],vis,W);
            }
        }
        return r;
    }
};
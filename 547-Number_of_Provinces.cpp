#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int res=0;
        for(int u=0;u<n;u++)
        {
            if(!vis[u])
            {
                res++;
                dfs(u,isConnected,vis);
            }
        }
        return res;        
    }
    void dfs(int source,vector<vector<int>>& isConnected,vector<int>&vis){
        stack<int> st;
        st.push(source);
        while(!st.empty())
        {
            int v=st.top();
            st.pop();
            if(vis[v]) continue;
            vis[v]=1;
            for(int i=0;i<isConnected[v].size();i++)
            {
                if(isConnected[v][i]&&!vis[i]) st.push(i);
            }
        }
    }
};